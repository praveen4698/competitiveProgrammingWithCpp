#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
    struct node{
    	char A[10];
    	struct node* next;
	}; 
	void insertbeg(struct node **head,struct node **tail,char A[10])
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		strcpy(temp->A,A);
		temp->next = NULL;
		if( *head == NULL)
		{
			*head = temp;
			*tail = temp;
			return ;
		}
		temp->next = *head;
		*head = temp;
	}
	void insertend(struct node **head,struct node **tail,char A[10] )
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		strcpy(temp->A,A);
		temp->next = NULL;
		if( *tail == NULL)
		{
			*head = temp;
			*tail = temp;
			return ;
		}
		(*tail)->next = temp;
		  *tail = temp;
		  
	}
	void deletefront( struct node **head)
	{
		struct node* temp = *head;
		*head  = (*head)->next;
		free(temp);
		
	}
	void deleteend(struct node **head)
	{
		struct node *temp = *head;
		struct node *prev = NULL;
		if( *head == NULL)
		{   printf("list is empty\n");
			return ;
		}
		while( temp->next != NULL)
		{   prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		free(temp);	
	}
	void printlist(struct node * head)
	{
		struct node *temp = head;
		while( temp != NULL)
		{
			printf("%s\n",temp->A);
			temp = temp->next;
		}
	}
	int main()
	{
		struct node *head = NULL;
		struct node *tail = NULL;
		int n=0;
		while( n!=6)
		{
			printf("enter your choice \n");
			printf("1 : insert at front\n");
			printf("2 : insert at end\n");
			printf("3 : delete at front\n");
			printf("4 : delete at end\n");
			pritnf("5 : printlist\n");
			printf("6 : finish\n");
			scanf("%d",&n);
			if( n == 1)
			{   char t[10];
				printf("enter the element : \n");
				scanf("%d",t);
				insertbeg(&head,&tail,t);
				}
			if( )	
			
		}
	}
