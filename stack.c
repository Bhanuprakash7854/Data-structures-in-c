
#include<stdio.h>
#define MAX 5

int stack[MAX],top = -1;
void push();
void pop();
void peek();
void display();

void main(){

	while(1)
	{
		int choice;
		printf("\nEnter the operation :\n");
		printf("1.push\n2.pop\n3.peek\n4.disiplay\n5.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:peek();
			break;
			case 4:display();
			break;
			case 5:return;
		}
	}
}


void push()
{
	
	if(top==MAX-1)
	{
		printf("stack is full\n");
	}
	else
	{
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	top++;
	stack[top]=n;
	}
}



void pop()
{
	
	if(top<0)
	{
		printf("Stack is empty\n");
	}
	else
	top--;
}


void peek()
{
	printf("top element is %d",stack[top]);
}


void display()
{
	for(int i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}
