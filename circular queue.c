//circular queue using array in c
//Written by:Bhanu Prakash

#include<stdio.h>
#include<stdlib.h>
#define MAX 2

void insert();
void Delete();
void display();
int queue[MAX];
int front =0,rear=-1;

void main(){
	
	while(1)
	{
		int choice;
		printf("Enter your choice:\n");
		printf("1.insert\n2.Delete\n3.display\n4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			break;
			case 2:Delete();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
		}
	}
}

void insert()
{
	
	if((front == 0 && rear == MAX -1) || (front !=0 && rear != -1) && front == rear +1)
	{
		printf("queue is full");
		exit(0);
	}
	else
	{
		
		
		rear++;
		if(rear == MAX)
		{
			rear = (rear)%MAX;
		}
		int n;
		printf("Enter number to insert:");
		scanf("%d",&n);
		queue[rear] = n;
	}
}

void Delete()
{
	if(front == 0 && rear ==-1)
	{
		printf("queue is empty");
		exit(0);
	}
	else
	{
		front++;
	}
}


void display()
{
	int i;
	for(i=front;i!=rear;i++)
	{
		if(i == MAX){
			i = (i)%MAX;
			if(i==rear)
			break;
		}
		printf("%d\t",queue[i]);
	}
	printf("%d\n",queue[i]);
}
