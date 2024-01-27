#include<stdio.h>

void dfs(int v);
int a[10][10],visited[10],n;
void main()
{
	int i,j;
	printf("Enter no of verteices:");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	visited[i]=0;
	dfs(1);
}

void dfs(int v)
{
	int i;
	visited[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]==1 && visited[i]==0)
		{
			printf("\n%d->%d",v,i);
			dfs(i);
		}
	}
}