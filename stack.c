//stack implementation using array in c
//written by : Bhanu prakash


#include<stdio.h>
//here i am taking stack size as 5
#define MAX 5
//defining stack array as global so it can be acessed in all functions
int stack[MAX],top = -1;
void push();
void pop();
void peek();
void display();

void main(){
	//runnnig an infinite loop
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

//to insert an element in stack
void push()
{
	//if stack is full the program will exit
	if(top==MAX-1)
	return;
	
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	top++;
	stack[top]=n;
}


//to remove an element in stack
void pop()
{
	//if stack is empty and you try to pop the program will exit
	if(top<0)
	return;
	top--;
}

//to print the last inserted value in stack
void peek()
{
	printf("top element is %d",stack[top]);
}


//to disiplay all the values in stack
void display()
{
	for(int i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}
