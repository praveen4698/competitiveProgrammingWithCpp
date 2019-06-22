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
			for(int i = max_size-1;i>=0;i--)
			{
				
				bool val = pre_xor & (1<<i);
				if(temp->children[val] == NULL)
					temp->children[val] = newnode();
					
				temp = temp->children[val];	
				
			}
			temp->value = pre_xor;
    	}
		
		int query(trienode* root,int pre_xor)
		{
			trienode* temp = root;
			for(int i = max_size-1;i>= 0;i--)
			{
				bool val = pre_xor & (1 << i);
				if(temp->children[1-val] != NULL)
					temp = temp->children[1-val];
				else if(temp->children[val] != NULL)
					temp = temp->children[val];
			}
			return pre_xor^(temp->value);
		}
		
		int main()
		{
			int n;
			printf("enter the number of elements in array:\n");
			scanf("%d",&n);
			printf("enter the array:\n");
			int pre_xor = 0;
			int a;
			trienode* root = newnode();
			insert(root,0);
			int max = INT_MIN;
			int temp;
			for(int i = 0;i<n;++i)
			{
				scanf("%d",&a);
				pre_xor = a^pre_xor;
				insert(root,pre_xor);
				temp = query(root ,pre_xor);
		    	if(max < temp)
				{
					max = temp;
				}
			}
			printf("the maximum xor is : %d",max);
			return 0;
		}
		
