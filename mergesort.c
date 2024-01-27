#include <stdio.h>
#include <stdlib.h>
void mergesort(int low,int high);
void merge(int low,int mid,int high);
int a[10];
int main()
{
	int n,i;
	printf("enter a size:");
	scanf("%d",&n);
	printf("enter elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(0,n-1);
	printf("after sorting : ");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	return 0;
}
void mergesort(int low,int high)
{
	int mid;
	if(low!=high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
}
void merge(int low,int mid,int high)
{
	int i,j,k,temp[10];
	i=low;
	j=mid+1;
	k=low;
	while((i<=mid) && (j<=high))
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
	    }
	    else
	    {
	    	temp[k]=a[j];
	    	k++;
	    	j++; 	
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		k++;	
		i++;	
	}
	while(j<=high)
	{
		temp[k]=a[j];
		k++;	
		j++;	
	}
	for(i=low;i<=high;i++)
	a[i]=temp[i];
}