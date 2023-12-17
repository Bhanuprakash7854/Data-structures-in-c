//stack using linked list

#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void peek();
void display();

struct node
{
	int data;
	struct node* next;
}*first=NULL,*temp,*nn,*top;

int count = 0;

void main()
{
	while(1)
	{
		int choice;
		printf("Enter operation to perform:\n");
		printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:peek();break;
			case 4:display();break;
			case 5:exit(0);
		}
	}
}

void push()
{
	nn = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&nn->data);
	if(first==NULL)
	{
		first = nn;
		top=nn;
		top->next = NULL;
		count++;
	}
	else
	{
		top->next=nn;
		top = nn;
		top->next = NULL;
		count++;
	}
}

void pop()
{
	int i;
	temp = first;
	for(i=1;i<count-1;i++)
	temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	top = temp;
	count--;
}

void peek()
{
	printf("Top element is %d\n",top->data);
}

void display()
{
	int i;
	temp = first;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}