//program to convert infix expression to prefix expression using stack in c
//written by : Bhanu prakash

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15

int prec(char ch);
char pop();
void push(char ch);
char stack[MAX];
int top = -1;


int main(){
	
	char infix[15],prefix[15];
	//j variablle is to track the prefix string length
	int j=0;
	
	printf("Enter infix expression:");
	scanf("%s",infix);
	strrev(infix);
	printf("%s",infix);
	
	for(int i=0;infix[i]!='\0';i++){
		if(infix[i]==')')
		{
			push(infix[i]);
		}
		else if(infix[i]=='(')
		{
			while(stack[top]!=')')
			{
				prefix[j]=pop();
				j++;
			}
			pop();
		}
		else if((infix[i]>='a' && infix[i]<='z')||( infix[i]>='A' && infix[i]<='Z'))
		{
			prefix[j]=infix[i];
			j++;
		}
		else{
			if(prec(infix[i])>=prec(stack[top])){
				push(infix[i]);
			}
			else{
				while(prec(stack[top])>prec(infix[i]))
				{
					prefix[j]=pop();
					j++;
				}
				push(infix[i]);
			}
		}
	}
	while(top>=0)
	{
		prefix[j]=pop();
		j++;
	}
	
	prefix[j]='\0';
	strrev(prefix);
	printf("prefix expression : %s",prefix);
	
	return 0;
}

//to check prcedence of operators i have given some random integer values according to their actual precedence
//for example * has higher precedence than + so i gave 2 for * and 1 for +
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
	return 0;
}

//to insert a character in stack
void push(char ch)
{
	//if stack is full the program will exit
	if(top==MAX-1)
	{
		printf("stack overflow!!!");
		exit(0);
	}
	top++;
	stack[top]=ch;
}


//to remove a character from stack
char pop()
{
	//if stack is empty and you try to pop the program will exit
	if(top<0)
	{
		printf("stack underflow!!!");
		exit(0);
	}
	char ch = stack[top];
	top--;
	return ch;
}