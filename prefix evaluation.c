
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

void push(int n);
int pop();
int compute(int x,int y,char op);
char stack[MAX];
int top = -1;

void main(){
	char prefix[15];
	printf("Enter prefix expression:");
	scanf("%s",prefix);
	strrev(prefix);
	for(int i=0;prefix[i]!='\0';i++){
		if(prefix[i]>='a' && prefix[i]<='z' || prefix[i]>='A' && prefix[i]<='Z' )
		{
			int num;
			printf("Enter value of %c : ",prefix[i]);
			scanf("%d",&num);
			push(num);
		}
		else
		{
			int x = pop();
			int y = pop();
			push(compute(x,y,prefix[i]));
		}
	}
	
	printf("solution of the expression : %d",pop());
	
}



int compute(int x,int y,char op)
{
	switch(op)
	{
		case '+' : return x+y;
		break;
		case '-' : return x-y;
		break;
		case '*' : return x*y;
		break;
		case '/' : return x/y;
		break;
		case '%' : return x%y;
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
