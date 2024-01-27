
#include<stdio.h>
#include<stdlib.h>
#define MAX 15

int prec(char ch);
char pop();
void push(char ch);
char stack[MAX];
int top = -1;


void main(){
	
	char infix[15],postfix[15];
	
	int j=0;
	
	printf("Enter infix expression:");
	scanf("%s",infix);
	
	for(int i=0;infix[i]!='\0';i++){
		if(infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				postfix[j]=pop();
				j++;
			}
			pop();
		}
		else if((infix[i]>='a' && infix[i]<='z')||( infix[i]>='A' && infix[i]<='Z'))
		{
			postfix[j]=infix[i];
			j++;
		}
		else{
			if(prec(infix[i])>prec(stack[top])){
				push(infix[i]);
			}
			else{
				while(prec(stack[top])>=prec(infix[i]))
				{
					postfix[j]=pop();
					j++;
				}
				push(infix[i]);
			}
		}
	}
	while(top>=0)
	{
		postfix[j]=pop();
		j++;
	}
	
	postfix[j]='\0';
	printf("postfix expression : %s",postfix);
	
}


int prec(char ch)
{
	switch(ch)
	{
		case '(':
			return 0;
			break;
		case ')':
			return 0;
			break;
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '%':
			return 2;
			break;
	}
}


void push(char ch)
{
	
	if(top==MAX-1)
	{
		printf("stack overflow!!!");
		exit(0);
	}
	top++;
	stack[top]=ch;
}



char pop()
{
	
	if(top<0)
	{
		printf("stack underflow!!!");
		exit(0);
	}
	char ch = stack[top];
	top--;
	return ch;
}
