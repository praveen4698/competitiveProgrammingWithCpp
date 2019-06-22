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
     void reverselist(struct node **head_ref,struct node *head)
     {
         struct node * first;
         struct node * rest;
         if(*head_ref == NULL)
            return;
         first = *head_ref;
         rest = first->next;
         if(rest == NULL )
            return;
         reverselist(&rest,head);
         first->next->next = first;
         first->next = head;
     }
     void print(struct node * head)
	 {  int j = 8;
	    while(j--)
        {
        	printf("%d\n",head->data);
         	head = head->next;
		 }	 }

	 int countnode(struct node *head)
	 {  struct node *temp = head;
	    int count = 0;
	    while(temp->next != head)
	        count++;
	        count++;
	     return  count;
			  }
	 int main()
	 {
	   	struct node* head = NULL;
	 	int i;
	    push(&head,4);

		push(&head,5);
		print(head);
		struct node *headtemp = head;
	 	int count = countnode(head);
		printf("\n \n%d",count);
		reverselist(&head,headtemp);
		print(head);

	    return 0;
	 }

