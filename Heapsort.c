#include<stdio.h>
#include<stdlib.h>
void createheap();
void heapsort();
void delroot(int last);
void insert(int num,int loc);
int n,a[10];
int main()
{
	int i;
	printf("enter array size:");
	scanf("%d",&n);
	printf("enter array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	createheap();
	heapsort();
	printf("after sorting : ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	return 0;	
}
void createheap()
{
	int i;
	for(i=0;i<n;i++)
	insert(a[i],i);
}
void insert(int num,int loc)
{
	int parent;
	while(loc>0)
	{
		parent=(loc-1)/2;
		if(num<=a[parent])
		{
			a[loc]=num;
			return;
		}
		a[loc]=a[parent];
		loc=parent;
	}
	a[0]=num;
}
void heapsort()
{
	int i;
	for(i=n-1;i>0;i--)
	delroot(i);
}
void delroot(int last)
{
	int i=0,t,left,right;
	t=a[i];
	a[i]=a[last];
	a[last]=t;
	left=2*i+1;
	right=2*i+2;
	while(right<last)
	{
		if((a[i]>=a[left]) && (a[i]>=a[right]))
		return ;
		else if(a[left]>a[right])
		{
			t=a[i];
			a[i]=a[left];
			a[left]=t;
			i=left;
		}
		else
		{
		    t=a[i];
			a[i]=a[right];
			a[right]=t;
			i=right;	
		}
		left=2*i+1;
		right=2*i+2;	
	}
	if((left==last-1)&& (a[i]<=a[left]))
	{
		    t=a[i];
			a[i]=a[left];
			a[left]=t;
	}
}