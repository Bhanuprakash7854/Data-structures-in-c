

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void insert();
void Delete();
void display();

int queue[MAX];
int front=0,rear=-1;

void main()
{
	while(1)
	{
		int choice;
		printf("Enter the operation:\n");
		printf("1.insert\n2.delete\n3.display\n4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();break;
			case 2:Delete();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
}

void insert()
{
	if(rear==MAX-1)
	{
		printf("queue is full\n");
	}
	int n;
	printf("Enter the num:");
	scanf("%d",&n);
	rear++;
	queue[rear]=n;
}

void Delete()
{
	if(front>rear)
	{
		printf("Queue is empty!!");
	}
	else if(front==rear)
	{
		front =0;
		rear =-1;
	}
	else
	front++;
}

void display()
{
	int i;
	printf("Elements are:\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
	}
	printf("\n");
}
