#include<bits/stdc++.h>
using namespace std;
int nodes;
int dist[1000]={0};
int a[1000]={0};
int p[1000]={0};
int d[1000][1000]={0};
int min(int src)
{
	int x=1000,m;
	for(int i=src;i<nodes;i++)
	{if (a[i] == 0 && 
                   dist[i] <= x) 
            x= dist[i], m = i;
	}
	
	return m;
	
	
}
void print(int dest)
{
	
	if(p[dest]==-1)
	{return;
	}
	else
	{
		
		print(p[dest]);cout<<"  "<<dest;
	}
	
	
}
void segmented(int src,int dest)
{
	
	for(int i=src;i<nodes;i++)
	{
		a[i]=0;
		dist[i]=1000;
		p[i]=-1;
		
		
		
	}
	
	dist[src]=0;
	p[0]=-1;
	
	for(int c=0;c<nodes;c++)
	{
	
	int u=min(src);a[u]=1;
	
	for(int k=0;k<nodes;k++)
	{
		
		if(a[k]==0  && ( d[u][k]!=0)   &&  dist[u]+d[u][k]<dist[k])
		{
			p[k]=u;
			dist[k]=dist[u]+d[u][k];
		
		}	
		
	}
		
}
for(int n=0;n<nodes;n++)
	{cout<<"parent of "<<n<<" th node is "<<p[n]<<endl;
		}
	cout<<"total distance in the path is "<<dist[dest]<<endl;
	cout<<"path is "<<endl;
	cout<<"0 ";print( dest);	
	
}

int main()
{
	cout<<"enter no of nodes  ";
	
	cin>>nodes;
	

	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{    
			cout<<"enter cost between "<<i<< " and  "<<j<<" ";
			cin>>d[i][j];
			d[j][i]=d[i][j];
		}
	}
	

	
	int dest;
	cout<<"enter destination   ";
	cin>>dest;
	
	segmented(0,dest);
	cout<<endl;
	cout<<"enter the starting and ending node of failured link "<<endl;
	int s,o;
	cin>>s>>o;
	d[s][o]=1000;d[o][s]=1000;
	cout<<"AFTER FINDING SEGMENTED PATH between failed link "<<endl;
	segmented(0,dest);
	
return 0;	
}
