#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*front=NULL,*rear=NULL,*ptr,*nn;

void insert();
void Delete();
void display();

void main()
{
	while(1)
	{
		int choice;
		printf("Enter operation to perform:\n");
		printf("1.insert\n2.delete\n3.display\n4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();break;
			case 2:Delete();break;
			case 3:display();break;
			case 4:exit(0);break;
		}
	}
}

void insert()
{
	nn = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&nn->data);
	if(front == NULL)
	{
		front = nn;
		rear=nn;
		rear->next = NULL;
	}
	else
	{
		rear->next = nn;
		rear=nn;
		rear->next=NULL;
	}
}

void Delete()
{
	if(fornt==NULL)
	printf("Under flow\n");
	else
	{
	ptr = front;
	front=front->next;
	free(ptr);
	}
}

void display()
{
	ptr = front;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}