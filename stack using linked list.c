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
}*nn,*top=NULL,*temp;

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
	nn->next = top;
	top = nn;
}

void pop()
{
	top = top->next;
}

void peek()
{
	printf("Top element is %d\n",top->data);
}

void display()
{
	temp = top;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}