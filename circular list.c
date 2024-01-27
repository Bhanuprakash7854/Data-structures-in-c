
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*first = NULL,*temp,*nn,*ptr;

void create();
void Delete();
void insert();
void display();
int count=0;
void main()
{
	while(1)
	{
		int choice;
		printf("Enter operation to perform:\n");
		printf("1.create\n2.insert\n3.delete\n4.display\n5.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();break;
			case 2:insert();break;
			case 3:Delete();break;
			case 4:display();break;
			case 5:exit(0);
		}
	}
}

void create()
{
	int ch;
	do
	{
	nn = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&nn->data);
	if(first == NULL)
	{
		first = nn;
		temp = nn;
		first->next = first;
		count++;
	}
	else
	{
		temp->next = nn;
		temp = temp->next;
		temp->next = first;
		count++;
	}
	printf("Do you want to create again(1/0):");
	scanf("%d",&ch);
    }while(ch!=0);
}

void insert()
{
	int i,pos;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&nn->data);
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		nn->next = first;
		temp = first;
		for(i=1;i<count;i++)
		temp = temp->next;
		first = nn;
		temp->next = first;
		count++;
	}
	else if(pos>1 && pos <+count)
	{
		temp = first;
		for(i=1;i<pos-1;i++)
		temp = temp->next;
		nn->next = temp->next;
		temp->next = nn;
		count++;
	}
	else if(pos == count+1)
	{
		temp = first;
		for(i=1;i<count;i++)
		temp = temp->next;
		temp->next = nn;
		nn->next = first;
		count++;
	}
	else
	{
		printf("Invalid position");
	}
}


void Delete()
{
	int i,pos;
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		temp = first;
		ptr = first;
		first = first->next;
		for(i=1;i<count;i++)
		temp = temp->next;
		
		temp->next = first;
		free(ptr);
		count--;
	}
	else if(pos>1 && pos <count)
	{
		temp = first;
		for(i=1;i<pos-1;i++)
		temp = temp->next;
		ptr = temp->next;
		temp->next = ptr->next;
		free(ptr);
		count--;
	}
	else if(pos == count)
	{
		temp = first;
		for(i=1;i<count-1;i++)
		temp = temp->next;
		ptr = temp->next;
		temp->next = first;
		free(ptr);
		count--;
	}
	else
	{
		printf("Invalid position");
	}
}


void display()
{
	int i;
	temp = first;
	for(i=1;i<=count;i++)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
