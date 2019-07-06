#include<bits/stdc++.h>
#define max_size 32

	using namespace std;
	
		struct trienode
		{
		 	int value;
		 	trienode* children[2];
		};
		
		trienode* newnode()
		{
			trienode* temp = new trienode;
			temp->value = 0;
			temp->children[0] = NULL;
			temp->children[1] = NULL;
			return temp;
		}
		
		void insert(trienode* root,int pre_xor)
		{
			trienode* temp = root;
			for(int i= max_size - 1;i >= 0;i--)
			{
				bool val = pre_xor & ( 1<<i);
				if(temp->children[val] == NULL)
					temp->children[val] = newnode();
				temp = temp->children[val];	
			}
			temp->value = pre_xor;
		}
		
		int query(trienode* root,int pre_xor)
		{
			trienode* temp = root;
			for(int  i = max_size-1;i >= 0;i--)
			{
				bool val = pre_xor &(i<<i);
				if( temp->children[1-val] != NULL)
					temp = temp->children[1-val];
				else if( temp->children[val] != NULL)
					temp = temp->children[val];	
			}
			return pre_xor^(temp->value);
		}
		
		int main()
		{
			int n;
			printf("enter the total number of elements in array:\n");
			scanf("%d",&n);
			printf("enter the array:\n");
			trienode *root = newnode();
			int A[101] ;
			for(int i=0;i<n;++i)
			{
				scanf("%d",&A[i]);
				insert(root,A[i]);
			}
			int max_xor = INT_MIN;
			int temp = 0;
			for(int i = 0;i<n;++i)
			{
				temp = query(root,A[i]);
				if(temp > max_xor)
					max_xor = temp;
			}
			
			printf("the maximum xor is : %d\n",max_xor);
			return 0;
		}
		
		
		
