#include<stdio.h>
#include<stdlib.h>
     
    struct tree
	{
    	int data;
    	struct tree* left;
    	struct tree* right;
	}; 
	
	
	struct tree* insertion(struct tree *head,int data)
	{
		if(head == NULL)
		{
			struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
			temp->data = data;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}
		
		if(head->data > data)
		  head->left = insertion(head->left,data);
		else if(head->data < data)
		 head->right =  insertion(head->right,data);  
		 
		 return head;
	}
	
	
	void printinorder(struct tree *head)
	{   
	
	    if(head == NULL)
	          return ;
		printinorder( head->left);
		printf("%d ",head->data);
		printinorder(head->right);
	}
	
	void printpreorder(struct tree *head)
	{
		
		if(head == NULL)
		  return ;
		  
		printf("%d ",head->data);
		printpreorder(head->left);
		printpreorder(head->right);
		  
	}
	
	void printpostorder(struct tree * head)
	{
		if(head == NULL)
		  return ;
		  
		printpostorder(head->left);
		printpostorder(head->right);
		printf("%d ",head->data);
		  
	}
	struct tree* minValue(struct tree* head)
    {
         struct tree* current = head;
 
    
         while (current->left != NULL)
            current = current->left;
 
            return current;
           }
 

    struct tree* deletenode(struct tree* head, int data)
    {
    
    if (head == NULL) return head;
 
  
    if (data < head->data)
        head->left = deletenode(head->left, data);
 
  
    else if (data > head->data)
        head->right = deletenode(head->right, data);
 
    
    else
    {

        if (head->left == NULL)
        {
            struct tree *temp = head->right;
            free(head);
            return temp;
        }
        else if (head->right == NULL)
        {
            struct tree*temp = head->left;
            free(head);
            return temp;
        }
 
   
        struct tree* temp = minValue(head->right);
 
        
        head->data = temp->data;
 
       
        head->right = deletenode(head->right, temp->data);
    }
    return head;
     }
	int countnode(struct tree* head)
	{
		if(head == NULL)
		   return 0;
		
		else 
		return (countnode(head->left) + countnode(head->right) +1)   ;
	}
	
	int main()
	{
	    struct tree* head = NULL;
        FILE *tree = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\insertiontree.txt","r");
        
        int h ;
        fscanf(tree,"%d",&h);
        int i;
        for(i=0;i<h;++i)
        {
        	int t;
        	fscanf(tree,"%d ",&t);
        	head  = insertion(head,t);
		}
        
        
        fclose(tree);
		
	    printf("enter your choice\n");
	    printf("1 : insertion\n");
	    printf("2 : preorder traversal\n");
	    printf("3 : postorder traversal\n");
	    printf("4 : inderorder traversal\n");
	    printf("5 : delete a node\n");
	    printf("6 : exit\n");
	    int n ;
	    scanf("%d",&n);	
	    while(n != 7)
	    {
	   	    if(n == 1)
	   	     {
	   		    int data;
	   		  	printf("enter the number : ");
	   		  	scanf("%d",&data);
	   		  	head = insertion(head,data);
				 }
			if(n == 2)
			  {  
			    printf("\n");
		 	    printpreorder(head);
		 	    printf("\n");
	        	}
			if(n == 3)
			 {
			 	printf("\n");
			    printpostorder(head) ;
			    printf("\n");
			  }
			if(n==4)
			 {
			   	printf("\n");
			    printinorder(head); 
				printf("\n"); 
			  }
			if(n == 5)
			{
				printf("\nenter the data to be deleted from the tree : ");
				int t;
				scanf("%d",&t);
				head = deletenode(head,t);
			 } 
			if(n==6)
			{   printf("\n");
				printf("number nodes in given graph is : ");
				int t = countnode(head);
				printf("%d\n",t);
			 } 
			  
			 printf("enter your choice\n");
	         printf("1 : insertion\n");
	         printf("2 : preorder traversal\n");
	         printf("3 : postorder traversal\n");
	         printf("4 : inderorder traversal\n");
	         printf("5 : delete a node\n");
	         printf("6 : count the number of nodes\n");
	         printf("7 : exit\n");  
	         scanf("%d",&n);
	       
			  	 
		   }
      	return 0;	
	  }  
