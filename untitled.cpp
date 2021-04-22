#include <iostream>

void cross(int m, int n, int x, int y)
	{
		int arr[m][n], i, j;
		
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				if((i==x-j)&&(j==y+j)||(i==x-j)&&(j==y-j)||(i==x+j)&&(j==y+j)||(i==x+j)&&(j==y-j))
					arr[i][j]='*'
				else
					arr[i][j]='.'
			}
		}
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
			{
				cout<<a[i][j];
			}
			cout<<"\n";
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
		cross(a[i],b[i],c[i],d[i])
		cout<<endl<<endl;
	}
}