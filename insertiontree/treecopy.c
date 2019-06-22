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

	struct tree* copy1(struct tree* head1,struct tree* head2)
	{
	    if( head1 == NULL)
	      return NULL ;

	  /*	struct tree* temp = malloc(sizeof(struct tree));
	  	temp->data = head1->data;
	  	temp->left = NULL;
	  	temp->right = NULL;
	    temp->left = copy(head1->left,temp->left);
	    temp->right = copy(head2->right,temp->right);
	  	head2 = temp;
	  	return head2;*/
	}

    int main()
    {
    	struct tree* head1 = NULL;
    	struct tree* head2 = NULL;
    	FILE *tree  = fopen("C:\\Users\\praveen yadav\\Documents\\New folder\\copytree.txt","r");
    	int h;
    	fscanf(tree,"%d",&h);
    	int i;
    	   for(i=0;i<h;++i)
    	   {
    	   	    int t;
    	   	    fscanf(tree,"%d ",&t);
    	   	    head1 = insertion(head1,t);
		   }
	//	printf("before copy :  \n") ;
        printinorder(head1);
		head2 = copy1(head1,head2);
		printinorder(head2);

		return 0;
	}
