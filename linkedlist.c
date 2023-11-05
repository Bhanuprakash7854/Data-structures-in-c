#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert();
void Delete();

struct node
{
	int data;
	struct node* next;
}*first=NULL,*temp,*nn,*ptr;

int count=0;
void main()
{
	while(1)
	{
		int choice;
		printf("Enter the operation:\n");
		printf("1.create\n2.insert\n3.display\n4.delete\n5.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();break;
			case 2:insert();break;
			case 3:display();break;
			case 4:Delete();break;
			case 5:exit(0);
		}
	}
}

void create()
{
	int choice,i;
	do{
	nn = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&nn->data);
	nn->next = NULL;
	if(first==NULL)
	{
		first = nn;
		temp = nn;
	}
	else
	{
		temp->next=nn;
		temp = nn;
	}
	count++;
	printf("Do you want to create another node(1/0):");
	scanf("%d",&choice);
	}while(choice!=0);
}

void insert()
{
	int pos,i;
	nn = (struct node*)malloc(sizeof(struct node));
	printf("Enter the number:");
	scanf("%d",&nn->data);
	nn->next = NULL;
	printf("Enter position to insert:");
	scanf("%d",&pos);
	if(pos==1)
	{
		nn->next = first;
		first = nn;
		count++;
	}
	else if(pos == count+1)
	{
		temp = first;
		for(i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = nn;
		count++;
	}
	else if(pos>1 && pos<=count)
	{
		temp = first;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		nn->next = temp->next;
		temp->next = nn;
		count++;
	}
	else
	{
		printf("Invalid position!!");
	}
}

void display()
{
	int i;
	temp = first;
	for(i=1;i<=count;i++)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Delete()
{
	int pos,i;
	printf("Enter the position to delete:");
	scanf("%d",&pos);
	if(pos == 1)
	{
		temp = first;
		first = first->next;
		free(temp);
		count--;
	}
	else if(pos>1 && pos<count)
	{
		temp = first;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		ptr = temp->next;
		temp->next = ptr->next;
		free(ptr);
		count--;
	}	
	else if(pos==count)
	{
		temp = first;
		for(i=1;i<count-1;i++)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		count--;
	}
	
}