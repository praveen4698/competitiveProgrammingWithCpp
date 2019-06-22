#include<stdio.h>
#include<stdlib.h>
 
    struct tree
	{
    	int data;
    	struct tree *left;
    	struct tree *right;
    
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
	
	int compare(struct tree* head1,struct tree * head2)
	{
		if(head1 == NULL && head2 == NULL)
		   return 1;
		   
		if( head1 != NULL && head2 != NULL)
		{ 
		   return ( head1->data == head2->data && 
		        compare(head1->left,head2->left)&&
				compare(head1->right,head2->right));
			
		   }
		return 0;      
	}
	int main()
	{
		struct tree* head1 = NULL;
		struct tree* head2 = NULL;
		FILE *tree = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\compare1.txt","r");
		int n;
		fscanf(tree,"%d",&n);
		int i;
		   for(i=0;i<n;++i)
		   {
		   	    int t;
		   	    fscanf(tree,"%d ",&t);
		   	    head1 = insertion(head1,t);
		   }
		fclose(tree);
		tree = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\compare2.txt","r");
		fscanf(tree,"%d",&n);
		    for(i=0;i<n;++i)
			{
				int t;
				fscanf(tree,"%d ",&t);
				head2 = insertion(head2,t);
			   } 
			   
		int h = compare(head1,head2);
		if( h == 1)
		  printf("same\n");
		 else
		  printf("different\n"); 
		return 0 ;  	     
	}
