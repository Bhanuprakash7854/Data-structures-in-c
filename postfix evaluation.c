

#include<stdio.h>
#include<stdlib.h>
#define MAX 15

void push(int n);
int pop();
int compute(int x,int y,char op);
char stack[MAX];
int top = -1;

void main(){
	char postfix[15];
	printf("Enter postfix expression:");
	scanf("%s",postfix);
	for(int i=0;postfix[i]!='\0';i++){
		if(postfix[i]>='a' && postfix[i]<='z' || postfix[i]>='A' && postfix[i]<='Z' )
		{
			int num;
			printf("Enter value of %c : ",postfix[i]);
			scanf("%d",&num);
			push(num);
		}
		else
		{
			int x = pop();
			int y = pop();
			push(compute(x,y,postfix[i]));
		}
	}
	
	printf("solution of the expression : %d",pop());
	
}



int compute(int x,int y,char op)
{
	switch(op)
	{
		case '+' : return y+x;
		break;
		case '-' : return y-x;
		break;
		case '*' : return y*x;
		break;
		case '/' : return y/x;
		break;
		case '%' : return y%x;
		break;
 	}
}



void push(int n)
{
	
	if(top==MAX-1)
	{
		printf("stack overflow!!!");
		exit(0);
	}
	top++;
	stack[top]=n;
}



int pop()
{
	
	if(top<0)
	{
		printf("stack underflow!!!");
		exit(0);
	}
	int n = stack[top];
	top--;
	return n;
}
