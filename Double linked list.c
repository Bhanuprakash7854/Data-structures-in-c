#include<stdio.h>
#include<stdlib.h>
int count =0;
struct node
{
	int data;
	struct node* prev;
	struct node* next;
}*nn,*head = NULL,*temp;
void create();
void insert();
void display();
void Delete();
void main()
{
	while(1)
	{
		int choice;
		printf("\noperation to be performed :\n");
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
	int choice;
do
{
	nn = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&nn->data);
	nn->prev = NULL;
	nn->next = NULL;
	if(head==NULL)
	{
		head = nn;
		temp=nn;
	}
	else
	{
		temp->next = nn;
		nn->prev = temp;
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
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&nn->data);
	nn->prev = NULL;
	nn->next = NULL;
	printf("Enter position :");
	scanf("%d",&pos);
	if(pos==1)
	{
		nn->next = head;
		head->prev = nn;
		head = nn;
		count++;
	}
	else if(pos == count+1)
	{
		temp = head;
		for(i=1;i<pos-1;i++)
		temp = temp->next;
		temp->next = nn;
		nn->prev = temp;
		count++;
	}
	else if(pos>1 && pos<=count)
	{
		temp = head;
		for(i=1;i<pos-1;i++)
		temp = temp->next;
		temp->next->prev = nn;
		nn->next = temp->next;
		temp->next = nn;
		nn->prev = temp;
		count++;
	}
	else
	{
		printf("Invalid position\n");	
	}
}

void Delete()
{
	int pos;
	printf("Enter position :");
	scanf("%d",&pos);
	if(pos==1)
	{
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
		count--;
	}
	else if(pos == count)
	{
		temp = head;
		for(int i=1;i<pos-1;i++)
		temp = temp->next;
		free(temp->next);
		temp->next = NULL;
		count--;
	}
	else if(pos>1 && pos<count)
	{
		temp = head;
		for(int i=1;i<pos-1;i++)
		temp = temp->next;
		struct node* ptr = temp->next;
		ptr->next->prev = temp;
		temp->next = ptr->next;
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
	temp = head;
	for(int i=1;i<=count;i++)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
