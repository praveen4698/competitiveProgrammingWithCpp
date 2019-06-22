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
     void reverselist(struct node **head_ref)
     {
        struct node *prev = NULL;
        struct node *current = *head_ref;
        struct node *next = NULL;
         if(*head_ref == NULL)
         {

             printf("list is empty\n");
             return ;
         }
        while( next != *head_ref)
        {
            next = current->next;
            current->next = prev;
            prev = current ;
            current = next;
            }
          next->next =  prev;
          *head_ref = prev;
     }
     void print(struct node *head)
	 {  struct node *temp = head;
	   if( head == NULL)
       {
           printf("list is empty\n");
       }
       if (head != NULL)
       {
        do
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
        while (temp != head);
           }
    }

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
	   	printf("enter your choice\n");
	   	printf("1 : push\n");
	   	printf("2 : delete\n");
	   	printf("3 : reverse the list\n");
	   	printf("4 : count the number node in the list\n");
	   	printf("5 : print the list\n");
	   	printf("6 : exit\n");
	   	int n ;
	   	scanf("%d",&n);
	   	printf("\n\n");
	 	while( n != 6)
         {
             if(n == 1)
             {  printf("enter the number : ");
                 int t;
                 scanf("%d",&t);
                 push(&head,t);
                 }
              if(n == 2)
              {
                  printf("enter the number : ");
                  int t;
                  scanf("%d",&t);
                  deletenode(&head,t);
                  }
                if(n==3)
                {
                    reverselist(&head);

                }
                if(n == 4)
                {
                    printf("number node in the list is : %d\n",countnode(head));
                }
                if(n == 5)
                {

                    print(head);
                }
                printf("\n\n");
                printf("1 : push\n");
	   	        printf("2 : delete\n");
	         	printf("3 : reverse the list\n");
	         	printf("4 : count the number of node in list\n");
	   	        printf("5 : print the list\n");
	   	        printf("6 : exit\n");
                 scanf("%d",&n);

         }
	    return 0;
	 }
