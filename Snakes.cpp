#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESCAPE 27

using namespace std;

struct Snake
{
    Snake *next;
    char *down;

} *front, *rear, *temp, *newnode;


char a[20][20];
int x,y,z;

void initial(char a[20][20]);
void display(char a[20][20]);
void apple(char a[20][20]);
void move(char a[20][20]);


void SetColor(int ForgC)
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, ForgC | FOREGROUND_INTENSITY);
}


int main()
{
	z=0;
    srand(time(NULL));
    initial(a);
}


void initial(char a[20][20])
{
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            a[i][j]='.';

    a[1][1]='o';
    a[1][2]=(char)15;

    front= new Snake;
    front->down=&a[1][2];

    rear= new Snake;
    rear->down=&a[1][1];

    rear->next=front;
    front->next=NULL;

    apple(a);
    display(a);
    cout<<"START?"; 
    move(a);

}


void apple(char a[20][20])
{
    x=rand()%19+1;
    y=rand()%19+1;
    if(a[x][y]=='.')
       a[x][y]=(char)2;
    else
        apple(a);
}


void move(char a[20][20])
{
    char *c;

    int i, j;

    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            if(a[i][j]==(char)15)
            {
                x=i;
                y=j;
            }

    temp=rear;
    c=rear->down;

    while(temp->next!=front)
    {
        temp->down=(temp->next)->down;
        temp=temp->next;
    }

    temp->down=front->down;
    *front->down='o';

    char ch;
    
    ch=getche();
    if(ch!=27)
        ch=getche();
	
    system("cls");

    switch(ch)
    {
        case UP:
            if(x==0)
                front->down=&a[19][y];
            else
                front->down=&a[x-1][y];
            break;

        case LEFT:
            if(y==0)
                front->down=&a[x][19];
            else
                front->down=&a[x][y-1];
            break;

        case DOWN:
            if(x==19)
                front->down=&a[0][y];
            else
                front->down=&a[x+1][y];
            break;

        case RIGHT:
            if(y==19)
                front->down=&a[x][0];
            else
                front->down=&a[x][y+1];
            break;

        case ESCAPE:
            initial(a);
            break;

        default:;
   }
   

    if(*front->down!='o')
    {
        if(*front->down=='.')
            *c='.';

        else
        {
        	z++;
            apple(a);
            newnode=new Snake;
            newnode->down=c;
            *c='o';
            newnode->next=rear;
            rear=newnode;
        }
        *front->down=(char)15;

        display(a);
        move(a);
   }

    else
    {
    	SetColor(12);
        cout<<"GAME OVER!\nFINAL SCORE: "<<z;
        exit(1);
    }

}


void display(char a[20][20])
{	
	SetColor(14);
	cout<<"\t\tScore: "<<z<<"\n \n";
    for(int i=0; i<20; i++)
    {
		SetColor(14);
        for(int j=0; j<20; j++)
        {
        	if(a[i][j]==(char)2)
        		SetColor(3);
        	else if(a[i][j]==(char)15)
        		SetColor(4);
        	else if(a[i][j]=='o')
        	 	SetColor(2);
        	else
				SetColor(14);
				
            cout<<a[i][j]<<" ";
        }
        SetColor(14);
        cout<<endl;
    }
}