#include<iostream>
using namespace std;

int main()
{
	int t=0;
	int n; 
	int m;//�������������
	int vol=0;
	int s[100];   //�������
	int u[10000]; //�����ֵ
	int v[100][100];
	int val=0;	
	cin>>t;
	while(t>0)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>vol>>val;
			s[i]=vol;  
			u[i]=val;//ÿ������������ֵ
		}
		for(int i=0;i<=n;i++)
			v[i][0]=0;
		for(int i=0;i<=m;i++)
			v[0][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				v[i][j]=v[i-1][j];
				if(s[i]<=j)
				{
					if((v[i-1][j-s[i]]+u[i])>v[i][j])
					v[i][j]=v[i-1][j-s[i]]+u[i];
				}
					
			}
		cout<<v[n][m]<<endl;
		t--;
	}
}