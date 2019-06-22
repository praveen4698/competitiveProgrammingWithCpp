   
    #include<stdio.h>
    #include<stdlib.h>
      
        struct node{
        	char data;
        	struct node *next;
		}; 
		
		
		void push(struct node ** Top ,char data)
		{
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			temp->data = data;
			temp->next = *Top;
			*Top = temp; 
			
		}
		char pop(struct node **Top)
		{
			struct node *temp ;
			char data  ;
			if(*Top == NULL)
			 return -1;
			 
			temp = *Top;
			data = temp->data;
			*Top = (*Top)->next;
			free(temp);
			return data; 
		}
		
		int prec(char ch)
              {
              	    switch (ch)
                    {
                        case '+':
                        case '-':
                        return 1;
 
                        case '*':
                        case '/':
                        return 2;
 
                        case '^':
                        return 3;
                             }
                       return -1;
  
                      }
 
		
		
		
		int main()
		{   struct node *Top = NULL;
		    char s[100],out[100];
		    int count1 = 0,count2 =0 ;
		    printf("enter the valid infix notation : ");
		    scanf("%s",s);
		    int i = 0,j = 0;
		    for(i = 0; s[i] != '\0';++i)
		     {    
		     	 if(s[i] - '0' >= 0 && s[i] - '0' <= 9 )
		     	    {
					 out[++j] = s[i];
				
					 }
				  else
				  {
				  	if(s[i] == '(')
				  	    {
				  	    	push(&Top,s[i]);
				  	    	count1++;
				  	    	
						  }
				    		  
					else if(s[i] == ')')
					 {      char a ;
					        count2++;
					 	while( Top != NULL && Top->data != '(')
					 	     { a = Top->data;
							  out[++j] = pop(&Top);
							   
							  }
					
					 	    
					 	    char X = pop(&Top);
					 	         
					 	       }	  
					   
					   else 
					   {
					   	     while(Top != NULL && prec(s[i])  <= prec(Top->data ))
					   	     out[++j] = pop(&Top);
					   	    
					   	     push(&Top,s[i]);
						   }	
					    
			 }}
			   while(Top != NULL)
			   out[++j] = pop(&Top);
		if(count1 != count2)
		 printf("invalid input\n");
		else
		printf("the postfix notation is : %s",out);
		      return 0;
		}
		
		
