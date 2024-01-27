#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[],int low,int high);
void main()
{
	int a[10],n,i;
	printf("enter array size:");
	scanf("%d",&n);
	printf("enter array elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("elements after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
void quicksort(int a[],int low,int high)
{
	int i,j,key,temp;
	if(low<high)
	{
		key=low;
		i=low;
		j=high;
		while(i<j)
		{
			while((a[i]<=a[key]) && (i<high))
			i++;
			while((a[j]>a[key]) && (j>low))
			j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[j];
		a[j]=a[key];
		a[key]=temp;
		quicksort(a,0,j-1);
		quicksort(a,j+1,high);
	}
}