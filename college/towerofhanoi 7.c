#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
   
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
		int pop(struct node **Top)
		{
			struct node *temp ;
			int data  =  0;
			if(*Top == NULL)
			 return -1;
			 
			temp = *Top;
			data = temp->data;
			*Top = (*Top)->next;
			free(temp);
			return data; 
		}
		int main()
		{
			struct node *Topa = NULL,*Topb =NULL,*Topc = NULL;
			push(&Topa,INT_MAX);
			push(&Topb,INT_MAX);
			push(&Topc,INT_MAX);
			int i,n;
			printf("enter the value of n : ");
			scanf("%d",&n);
			for(i=n;i>0;--i)
			     push(&Topa,i);
			     
			int max = pow(2,n) - 1;
			 
			for(i=1;i<max+1;++i)
			{
				if((i%3 == 1 && n%2 ==0) || (n%2 == 1 && i%3 == 2))
				{
					if(Topa->data > Topb->data)
					{
						printf("move disk number %d from B To A \n",Topb->data);
						push(&Topa,pop(&Topb));
					}
					else 
					{
						printf("move disk number %d from A To B \n",Topa->data);
						push(&Topb,pop(&Topa));
					}
				}
				if((i%3 == 2 && n%2 == 0) || (i%3 == 1 && n%2 == 1))
				{
					if(Topa->data > Topc->data)
					{
						printf("move disk number %d from C To A \n",Topc->data);
						push(&Topa,pop(&Topc));
					}
					else
					{
						printf("move disk number %d from A To C \n",Topa->data);
						push(&Topc,pop(&Topa));
					}
				}
				if(i%3 == 0)
				{
					if(Topb->data > Topc->data)
					{
						printf("move disk number %d from C To B \n",Topc->data);
						push(&Topb,pop(&Topc));
					}
					else
					{
						printf("move disk number %d from B To C \n",Topb->data);
						push(&Topc,pop(&Topb));
					}
				}
			}
			     return 0;
			
		}
