#include<stdio.h>
#include<stdlib.h>
int a[10][10];
int main()
{
	int n,i,j,queue[10],front=0,rear=-1,visit[10],v,visited[10];
	printf("enter no.of vertices:");
	scanf("%d",&n);
	printf("enter adjecency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter initial vertex to traverse:");
	scanf("%d",&v);
	visited[v]=1;
	printf("visited vertices: ");
	printf("%d\t",v);
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if((a[v][j]==1) && visited[j]!=1 && visit[j]!=1)
			{
				queue[++rear]=j;
				visit[j]=1;
			}
		}
		v=queue[front++];
		printf("%d\t",v);
		visit[v]=0;
		visited[v]=1;
	}
}