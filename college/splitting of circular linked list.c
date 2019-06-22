#include<stdio.h>
#include<stdlib.h>
   
     struct node{
     	int data;
     	struct node* next;
     	
	 };
	 
	 void push(struct node **head,int data)
	 {
	 	struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
	 	 struct node *temp = *head;
	 	 ptr1->data = data;
	 	 ptr1->next = *head;
	 	 
	 	  if(*head != NULL)
	 	  {
	 	  	while(temp->next != *head)
	 	  	  temp = temp->next;
	 	  	  
	 	  	temp->next = ptr1;
			     
		   }
		   else ptr1->next = ptr1;
		   
		   *head = ptr1;
	 }
	 void print(struct node * head)
	 {  int j = 8;
	   while(j--)
        {
        	printf("%d\n",head->data);
        	head = head->next;
			 }	 }
			 
		void splitlist(struct node *head,struct node **head1_ref ,struct node **head2_ref)
		{
			struct node *slow_ptr;
			struct node *fast_ptr;
			
			if(head == NULL)
			 return ;
			while(fast_ptr->next != head || fast_ptr->next->next != head)
			{
				fast_ptr = fast_ptr->next->next;
				slow_ptr = slow_ptr->next;
				 
			 } 
			 
			 if(fast_ptr->next->next == head)
			   fast_ptr = fast_ptr->next;
			   
			  *head1_ref = head;
			  
			  if(head->next != head) 
			    *head2_ref = slow_ptr->next;
			  
			  fast_ptr->next = slow_ptr->next;
			  slow_ptr->next = head;}  
			 
			 	 
