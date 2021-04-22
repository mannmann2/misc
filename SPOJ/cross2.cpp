#include <iostream>
using namespace std;

int max(int a, int b)
{
	if(a>b)
		return a;
	else 
		return b;
}

void cross(int m, int n, int x, int y)
{
	char arr[m][n], i, j,k,p,q,r,s;

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			for(k=0; k<=max(i,j); k++)
			{	
				if(x-k>-1)
					p=x-k;
				q=x+k;
				if(y-k>-1)
					r=y-k;
				s=y+k;
				if(((i==p)and(j==r))||((i==p)and(j==s))||((i==q)and(j==r))||((i==q)and(j==s)))
					arr[i][j]='*';
				else
					arr[i][j]='.';
			}

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
}

int main()
{
	int t,i;
	cin>>t;
	int a[t],b[t],c[t],d[t];

	for(i=0; i<t; i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}

	for(i=0; i<t; i++)
	{
		cross(a[i],b[i],c[i]-1,d[i]-1);
		cout<<endl<<endl;
	}
}