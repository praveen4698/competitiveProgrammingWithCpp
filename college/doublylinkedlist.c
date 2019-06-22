#include<stdio.h>
#include<stdlib.h>

    struct node
	{
     	int data;
     	struct node * prev;
     	struct node * next;
	};
	
	struct node* createnode(int data)
	{
		struct node * temp = malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
		
	}
	struct node* insertfront(struct node* head,int data)
	{
		struct node* temp = createnode(data);
		if(head == NULL)
		  return temp;
		head->prev = temp;  
		temp->next = head;
		
		return temp;
	}
	struct node* insertend(struct node* head ,int data)
	{
		if(head == NULL)
		{
			struct node* temp =  createnode(data);
			return temp;
		}
		else if( head->next == NULL)
		{   
		    struct node* temp = createnode(data);
			head->next = temp;
			temp->prev = head;
			return head;
		}
		else
		{
			head->next = insertend(head->next,data);
			return head;
		}
	}
	
	struct node* insertafter(struct node* head,int count,int data)
	{
		if(head == NULL)
		{
			printf("list is emppty\n");
			return NULL;
		}
		struct node* temp = createnode(data);
		struct node* present = head;
		while(present->data != count && present != NULL)
		{
		
			present = present->next;
		}
		if(present == NULL)
		{
		   printf("invalid input\n");
		   return head; 	
		   }
		temp->next = present->next;
		temp->prev = present;
		present->next = temp;
		return head;
	}
	
	
	void printlist(struct node* head )
	{
		while(head != NULL)
		{
		    if(head->prev != NULL)
			  printf(" %d ",head->prev->data);
			else printf(" NULL "); 
			
			printf(" %d ",head->data);
			
			if(head->next != NULL)
			  printf(" %d ",head->next->data);
			else printf(" NULL ");
			
			printf("\n");
			head = head->next;   	
		}
		printf("\n\n");
	}
	
	struct node* deletenode(struct node* head,int data)
	{
		if(head == NULL)
		{
		    printf("list is empty\n");
			return NULL;	
		}
		struct node* present = head;
		struct node* prev = NULL;
		while( present->data != data && present != NULL)
		{
			prev = present;
			present = present->next;
		}
		if(present == NULL)
		{
			printf("invalid input\n");
			return head;
		}
		prev->next = present->next;
		if( present->next != NULL)
              present->next->prev = prev;
              
        free(present);
		return head;      
	}
	int countnode(struct node* head)
	{
		if(head == NULL)
		return 0;
		return 1+ countnode(head->next);
	}
	struct node* reverselist(struct node *head)
    {
        struct node *temp = NULL;  
        struct node *current = head;
      
   
        while (current !=  NULL)
       {
           temp = current->prev;
           current->prev = current->next;
           current->next = temp;              
           current = current->prev;
         }      
      
     
         if(temp != NULL )
         head = temp->prev;
         
         return head;
         }     
	
	int main()
	{
		struct node* head = NULL;
		FILE *file = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\doublylinkedlist.txt","r");
		int V ;
		fscanf(file,"%d",&V);
		int i;
		  
		    for( i=0;i<V;++i)
		    {
		    	int a;
		    	fscanf(file,"%d",&a);
		    	head = insertend(head,a);
			}
        printf("enter your choice\n");
	    printf("1 : inserrt at front\n");
	    printf("2 : insert at end\n");
	    printf("3 : insert after a given number \n");
	    printf("4 : delete a given number\n");
	    printf("5 : reverse the list\n");
	    printf("6 : count the number of node\n");
	    printf("7 : print the list\n");
	    printf("10 : exit\n");
	   	int n ;
	   	printf("\n\n");
	   	scanf("%d",&n);
	   	printf("\n\n");
	   	while(n!= 10)
		   {
		   
	         if(n == 1)
             {  printf("enter the number : ");
                 int t;
                 scanf("%d",&t);
                 head = insertfront(head,t);
                 }
              if(n == 2)
              {
                  printf("enter the number : ");
                  int t;
                  scanf("%d",&t);
                  head = insertend(head,t);
                  }
                if(n==3)
                {
                   printf("enter the given number and data : ");
                   int a,b;
                   scanf("%d %d",&a,&b);
                   head = insertafter(head,a,b);

                }
                if(n == 4)
                {
                    printf("enter the number to be deleted : ");
                    int a;
                    scanf("%d",&a);
                    head = deletenode(head,a);
                }
                if(n == 6)
                {
                	printf("number node in the list is : %d \n\n", countnode(head));
				}
				if(n == 5)
				{
					head = reverselist(head);
				}
                if(n == 7)
                {

                    printlist(head);
                }
                
                printf("enter your choice\n");
	            printf("1 : inserrt at front\n");
	        	printf("2 : insert at end\n");
	        	printf("3 : insert after a given number \n");
	        	printf("4 : delete a given number\n");
	        	printf("5 : reverse the list\n");
	        	printf("6 : count the number of node\n");
	        	printf("7 : print the list\n");
	         	printf("10 : exit\n");
	         	  printf("\n\n");
                  scanf("%d",&n);
                  printf("\n\n");
           }
	   // head = insertafter(head,2,6);
	///	printlist(head);	
		return 0;
	}
