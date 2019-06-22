#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
   
     struct stacknode{
     	int data;
     	struct stacknode *next;
	 }; 
	 
	 struct stacknode* Newnode(int data)
	 {
	 	struct stacknode * stacknode = (struct stacknode *)malloc(sizeof(struct stacknode));
	 	stacknode->data = data;
	 	stacknode->next = NULL;
	 	return  stacknode;
	 	
	 }
	 
	 int isEmpty(struct stacknode* root)
	 {
	 	return !root;
	 	
	  } 
	
	 void push(struct stacknode** root,int data)
	 {
	 	
	   }  
	 
