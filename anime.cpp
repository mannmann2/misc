#include<conio.h>
#include<iostream>
using namespace std;

int main()
{
char ch;
char a[20];

a[9]=a[10]=a[11]='O';

long int k;
int i,j,m,n;

for(i=0; i<20; i++)
{
         if ((i!=9)&&(i!=10)&&(i!=11))
         a[i]=' ';
}

for(i=0;i<6;i++)
cout<<endl;



for(int x=0;x<10;x++)
{
n=12;
m=8;
for(i=0; i<8; i++)
{
         for(j=0; j<20; j++)
         cout<<a[j];
         for(j=0;j<18;j++)
         cout<<endl;
         for(k=0;k<30000000;k++);
         ch=a[m];
         a[m]=a[m+1];
         a[m+1]=ch;
         m--;
         
}
m++;
for(i=0; i<8;i++)
{
        for(j=0; j<20; j++)
        cout<<a[j]; 
        for(j=0;j<18;j++)
        cout<<endl;
        for(k=0;k<30000000;k++);
        ch=a[m+1];
        a[m+1]=a[m];
        a[m]=ch;
        m++;    
}

for(i=0; i<8;i++)
{
        for(j=0; j<20; j++)
        cout<<a[j]; 
        for(j=0;j<18;j++)
        cout<<endl;
        for(k=0;k<30000000;k++);
        ch=a[n];
        a[n]=a[n-1];
        a[n-1]=ch;
        n++;    
}
n--;
for(i=0; i<8;i++)
{
        for(j=0; j<20; j++)
        cout<<a[j]; 
        for(j=0;j<18;j++)
        cout<<endl;
        for(k=0;k<30000000;k++);
        ch=a[n];
        a[n]=a[n-1];
        a[n-1]=ch;
        n--;       
}
}
getch();
}
