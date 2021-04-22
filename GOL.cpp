#include<iostream>
#include<conio.h>
using namespace std;

int i, j, m, n, x, y, p, l, k=0;
char a[21][21], b[21][21], c='y', ch;

void GOL();

void initial()
{
    for(i=1;i<21;i++)
    {
                     for(j=1;j<21;j++)
                     {
                             a[i][j]='.';
                             b[i][j]='.';
                     }
    }  
}
    
void strct()
{
    cout<<"\t 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 20\n\n";
    for(i=1;i<21;i++)
    {
                     cout<<i<<"\t|";
                     for(j=1;j<21;j++)
                     {
                             cout<<a[i][j]<<"|";
                     }
                     cout<<"\n";
    }  
}

void beeb()
{
    for(i=1;i<21;i++)
    {
                     for(j=1;j<21;j++)
                     {
                             a[i][j]=b[i][j];
                     }
    }
    
    if(c=='y')
    l=k;
    
    if(k==l)
    {
            for(i=0;i<200;i++){cout<<"\n";} 
            cout<<"\t\t\tGeneration "<<k<<"\n\n";
            strct();
    }
    else GOL();
}


void life()
{
     cout<<"\nEnter coordinates\n";
     do
     {
            cin>>x>>y;
            a[x][y]='x';
            cout<<"\nEnter more? (Y/N)\n";
            cin>>ch;
     }
     while((ch=='Y')||(ch=='y'));
     cout<<"\n";
     strct();
}

void death()
{
     cout<<"Enter coordinates\n";
     do
     {
            cin>>x>>y;
            a[x][y]='.';
            cout<<"\nEnter more? (Y/N)\n";
            cin>>ch;
     }
     while((ch=='Y')||(ch=='y'));
     cout<<"\n";
     strct();
}

void GOL()
{
     k++;
     for(i=1;i<21;i++)
     {
     for(j=1;j<21;j++)
     {
     p=0;
     b[i][j]=a[i][j];
     for(m=i-1;m<=i+1;m++)
     {
     for(n=j-1;n<=j+1;n++)
     {
     if(!((m==i)&&(n==j)))
     {
     if(a[m][n]=='x')
     p++;
     }
     }
     }
     
     if(a[i][j]=='.')
     {
                     if(p>=3)
                     b[i][j]='x';
     }
     else
     {
         if((p<2)||(p>3))
         b[i][j]='.';
     }    
     }
     }
     beeb();
     here:
     cout<<"\n\n1 - Next Generation\n2 - Add Life\n3 - Kill\n4 - Go to specific future Generation\n5 - EXIT\n\n";
     cin>>ch;
     switch(ch)
     {
               case '1': c='y';
                         GOL();
                         break;
                         
               case '2': life();
                         goto here;
                         break;
                    
               case '3': death();
                         goto here;
                         break;
                    
               case '4': c='n';
                         cout<<"Enter generation number";
                         cin>>l;
                         GOL();
                         break;
                         
               case '5': exit(1);
                         break;
                    
               default: c='y';
                        GOL();
     }
}                 
                                                                                                
main()
{
   
    cout<<"\n\tThe Game of Life";
    getch();
    initial();
    cout<<"\n\n\n\t\t\tGeneration 0\n\n";
    strct();
    getch();
    life();
    cout<<"\nStart?\n";
    getch();
    GOL();
    getch();
}