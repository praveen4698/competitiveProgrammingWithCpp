#include<stdio.h>
#include<stdlib.h>
   
    struct tree
	{  
	   int data;
	   struct tree* left;
	   struct tree* right;
    	
	};
	
	struct tree* construct(int preorder[100],int ip,int ep,int inorder[100],int ii,int ei)
	{    printf("hj\n");
	     struct tree * temp = malloc(sizeof(struct tree));
	     temp->data = preorder[ip];
	     temp->left = NULL;
	     temp->right = NULL;
		 if( ep - ip == 0)
		   return temp;
		 else
		 {
		 	int x = temp->data;
		 	int i;
		 	int count = 0;
		 	for(i=ii;i<ei+1;++i)
		 	{
		 		if(inorder[i] != x)
		 		   count++;
		 		else 
				 break;   
			 }
			 
			 temp->left = construct(preorder,ip+1,ip+count+1,inorder,ii,ii+count);
			 temp->right = construct(preorder,ip+count+2,ep,inorder,count+2,ip);
			 return temp;
		   }  
		   return temp;
	}
	void printpostorder(struct tree * head)
	{
		if(head == NULL)
		  return ;
		  
		printpostorder(head->left);
		printpostorder(head->right);
		printf("%d ",head->data);
		  
	}
	
	
	int main()
	{
		struct tree * head = NULL;
		int preorder[100],inorder[100],ip,ep,ii,ei;
		int i;
		FILE *tree =  fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\inodertobinarytree.txt","r");
		int n;
		fscanf(tree,"%d",&n);
		
		   for(i=0;i<n;++i)
		   {    
		   	    fscanf(tree,"%d ",&preorder[i]);
		   }
		   for(i=0;i<n;++i)
		   {
		   	    fscanf(tree,"%d ",&inorder[i]);
		   }
		   head = construct(preorder,0,n-1,inorder,0,n-1);
		   printpostorder(head);
		   return 0;
	}
