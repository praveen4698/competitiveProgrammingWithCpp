   
    #include<stdio.h>
    #include<stdlib.h>
      
        struct node{
        	int data;
        	struct node *next;
		}; 
		
		
		void push(struct node ** Top ,int data)
		{
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			temp->data = data;
			temp->next = *Top;
			*Top = temp; 
			
		}
		void pop(struct node **Top)
		{
			struct node *temp ;
			int data  =  0;
			if(*Top == NULL)
			 { 
			  printf("stack is empty\n");
			 return ;}
			 
			temp = *Top;
		
			*Top = (*Top)->next;
			free(temp);
		 
		}
		void printstack(struct node* head )
		{
			struct node* temp = head;
			if(head == NULL)
			{
				printf("the stack is empty\n");
				return ;
				
			}
			while(temp != NULL )
			{
				printf("%d\n",temp->data);
				temp = temp->next;
			}
		}
		
		int main()
		{   struct node *Top = NULL;
		    printf("enter your choice\n");
		    printf("1 : push\n");
		    printf("2 : pop\n");
		    printf("3 : printlist\n");
		    printf("4 : exit\n");
		    int n;
		    scanf("%d",&n);
		    while( n != 4)
		    {
		    	if( n == 1)
		    	{
		    		printf("enter the number : \n");
		    		int t;
		    		scanf("%d",&t);
		    		push(&Top,t);
				}
				if( n == 2)
				{
					pop(&Top);
				}
				if( n == 3)
				{
					printstack(Top);
				}
		    printf("\n\n");		
			printf("enter your choice\n");
		    printf("1 : push\n");
		    printf("2 : pop\n");
		    printf("3 : printlist\n");
		    printf("4 : exit\n");
		    scanf("%d",&n);
			}
			 return 0;
		}
		
		
