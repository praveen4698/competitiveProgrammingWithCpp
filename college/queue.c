#include<stdio.h>
#include<stdlib.h>
  
    struct node{
    	int data;
    	struct node* next;
	};  
	void enqueue(struct node **head ,struct node **tail,int data)
	{
		struct node* temp = (struct node* )malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;
		struct node *tt = *tail;
		if( *head == NULL)
		{
			*head  = temp;
			*tail = temp;
			return;
		}
		tt->next = temp;
		*tail = temp;
		}
	void dequeue(struct node **head)
	{
		if(*head == NULL)
		 { printf("queue is empty\n");
		   return ;}
		
		struct node * temp = *head;
		*head = temp->next;
		free(temp);
		  
		}	
	
	void printlist(struct node * head)
	{
		struct node *temp = head;
		if(head == NULL)
		{
			printf("queue is empty\n");
			return ;
		}
		while(temp != NULL)
		{
			printf("%d \n",temp->data);
			temp = temp->next;
		}
		}	
	
	int main()
	{   struct node* head = NULL;
	     struct node* tail = NULL;
		 printf("enter your choice\n");
		 printf("1 : enqueue\n");
		 printf("2 : dequeue\n");
		 printf("3 : printlist\n");
		 printf("4 : exit\n");
		 int n;
		 scanf("%d",&n);
		 printf("\n\n");
		 while( n != 4)
		 {
		 	if( n == 1)
		 	{
		 		int t;
		 		printf("enter the number : ");
		 		scanf("%d",&t);
		 		enqueue(&head,&tail,t);
			 }
			 if( n == 2)
			 {
			 	dequeue(&head);
			 }
			 if( n == 3)
			 {
			 	printlist(head);
			 }
			 printf("\n\n");
			 printf("enter your choice\n");
		     printf("1 : enqueue\n");
		     printf("2 : dequeue\n");
		     printf("3 : printlist\n");
		     printf("4 : exit\n");
			 scanf("%d",&n);
		 }
		 return 0;
		}	
