#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node*left;
	int data;
	struct node*right;
}*nn,*root=NULL;
void insert(struct node*temp,struct node*nn);
void inorder(struct node*temp);
void preorder(struct node*temp);
void postorder(struct node*temp);
void search(struct node*temp);
int main()
{
	int ch,x;
	printf("binary search tree operations\n");
	while(1)
	{
		printf("\n1.insert 2.inorder 3.preorder 4.postorder 5.search 6.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					nn=(struct node*)malloc(sizeof(struct node));
					printf("enter data:");
					scanf("%d",&x);
					nn->data=x;
					nn->right=NULL;
					nn->left=NULL;
					insert(root,nn);
					break;
			case 2:
					inorder(root);
					break;
			case 3:
					preorder(root);
					break;
			case 4:
					postorder(root);
					break;
			case 5:
					search(root);
					break;
			case 6:
					exit(0);
					break;
			default:
				    printf("invalid choice");
		}
	}
	return 0;
}
void insert(struct node*temp,struct node*nn)
{
	if(root==NULL)
	{
		root=nn;
		printf("root node is added");
	}
	else if(nn->data < temp->data)
	{
		if(temp->left==NULL)
		{
			temp->left=nn;
			printf("node is added to left side");
		}
		else
		{
			insert(temp->left,nn);
		}		
	}
	else if(nn->data > temp->data)
	{
	    if(temp->right==NULL)
		{
		 temp->right=nn;
		 printf("node is added to right side");	
		} 
		else
		{
			insert(temp->right,nn);
		}
	}
}

void inorder(struct node*temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
void preorder(struct node*temp)
{
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node*temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
void search(struct node*temp)
{
	int x;
	printf("enter element to search:");
	scanf("%d",&x);
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			printf("element found");
			return;
		}
		else if(x<temp->data)
		{
			temp=temp->left;
		}
		else if(x>temp->data)
		{
			temp=temp->right;
		}
	}
	printf("element not found");
}