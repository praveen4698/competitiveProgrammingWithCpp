#include<stdio.h>
#include<stdlib.h>


    struct node
	{
        int data;
		struct node* left;
		struct node* right; 	
	};
	
	int max(int a , int b)
	{
		return a>b?a:b;
	}
	struct node* createnode( int data)
	{
		struct node* temp = malloc(sizeof(struct node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	
	int height(struct node * head)
	{
		if( head == NULL)
		 return 0;
		 
		return max( height(head->right) , height(head->left)) + 1;
	}
	
	struct node* rightrotation( struct node* head)
	{
		struct node *temp = head->left;
        struct node *temp2 = temp->right;
        temp->right = head;
        head->left = temp2;
        return temp;
	}
	struct node* leftrotation(struct node* head)
	{
	    struct node *temp = head->right;
        struct node *temp2 = temp->left;
        temp->left = head;
        head->right = temp2;
        return temp;
 
	}
	
    int balance1(struct node* head)
    {   
        if(head == NULL)
           return 0;
    	return (height(head->left) - height(head->right));
	  }
	  
	struct node* insertion( struct node* head,int data)
	{
		if(head== NULL)
		{
			return createnode(data);
		}
		
		if( data < head->data)
	       head->left = insertion(head->left,data);
		
		else 
		  head->right = insertion(head->right,data);
		  
		int balance = balance1(head);
	    printf("%d\n",balance);
		
	
        if (balance > 1 &&  data < head->left->data)
            return rightrotation(head);
 
    
        if (balance < -1 && data > head->right->data)
            return leftrotation(head);
 
   
        if (balance > 1 && data > head->left->data)
        {
            head->left =  leftrotation(head->left);
            return rightrotation(head);
            }
 
        if (balance < -1 && data < head->right->data)
        {
            head->right = rightrotation(head->right);
            return leftrotation(head);
         }  
		  return head;
	} 
	void print(struct node * head)
	{
		if(head != NULL)
		{
			print(head->left);
			printf("%d ",head->data);
			print(head->right);
		}
	  }  
	  
	int main()
	{
	  	int V;
	    struct node* head = NULL;
	  	FILE *file = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\AVL.txt","r");
	  
	  	fscanf(file,"%d",&V);
	  	int i;
	  	 
	  	    for(i = 0;i<V;++i)
	  	    {
	  	    	int a;
	  	    	fscanf(file,"%d",&a);
	  	    	head = insertion(head,a);
			  }
		print(head);
		return 0;	  
			  
	  }
