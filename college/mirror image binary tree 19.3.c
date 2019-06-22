#include<stdlib.h>
#include<stdio.h>
    struct tree
	 {
     	int data;
     	struct tree* right;
     	struct tree* left;
	 };
	struct tree* insertion(struct tree* head , int data)
	 {
	 	if(head == NULL)
	 	{
	 		struct tree *temp = malloc(sizeof(struct tree));
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

     
	struct tree* copy(struct tree* head)
	{
	    if( head == NULL)
	      return head ;
	  	
	    struct tree* temp = (struct tree*)malloc(sizeof(struct tree));
		temp->data = head->data;
		temp->left = copy(head->right);
		temp->right = copy(head->left);
		return temp; 
	}
	  
    int main()
    {
    	struct tree* head1 = NULL;
    	struct tree* head2 = NULL;
    	FILE *tree  = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\mirrorbinarytree.txt","r");
    	int h;
    	fscanf(tree,"%d",&h);
    	int i;
    	   for(i=0;i<h;++i)
    	   {
    	   	    int t;
    	   	    fscanf(tree,"%d ",&t);
    	   	    head1 = insertion(head1,t);
		   }
	 
	    printinorder(head1);
	    printf("\n");
		head2 = copy(head1);
		printinorder(head2);
		printf("\n");
	    
	
		
		return 0;   
	}
