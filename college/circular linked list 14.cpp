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
	   void deletenode(struct node **head, int key)
     {
      
            struct node* temp = *head, *prev;
  
  
            if (temp != NULL  && temp->data == key)
            {    
                prev = *head; 
		        while(prev->next != *head)
		        prev = prev->next;
			    *head = temp->next;
			    prev->next = temp->next;    
                free(temp);            
                return;
             }
            while (temp != *head && temp->data != key)
            {
                prev = temp;
                temp = temp->next;
               }
            if (temp == *head)
			    return;
            prev->next = temp->next;
			free(temp); 
            }
  
	 void print(struct node * head)
	 {  int j = 8;
	   while(j--)
        {
        	printf("%d\n",head->data);
        	head = head->next;
			 }	 }
	 		 
	 int main()
	 {
	   	struct node* head = NULL;
	 	int i;
	    push(&head,8);
		deletenode(&head,8); 
		push(&head,6);
		print(head);
	 	  
	 
	 }
