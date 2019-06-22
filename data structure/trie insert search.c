#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define intoint(c)  ((int)c - (int)'a')
	struct trienode
	{
	    struct trienode *children[26];
		bool isleaf;	
	};
	
	struct trienode* getnode(void)
	{
		struct trienode *pNode = malloc(sizeof(struct trienode));
		int i;
		for(i=0;i<26;++i)
		{
			pNode->children[i] = NULL;
		}
		pNode->isleaf = false;
		return pNode;
    }
    
    void insert(struct trienode* root, const char* key)
    {
    	int i ;
    	int length = strlen(key);
    	int index;
    	struct trienode* temp = root;
    	for(i=0;i<length;++i)
    	{
    		index = intoint(key[i]);
    		if(!temp->children[index])
    			temp->children[index] = getnode();
    		temp = temp->children[index];
		}
		temp->isleaf = true;
	}
	
	bool search(struct trienode* root, const char* key)
	{
		int i;
		int length = strlen(key);
		int index;
		struct trienode* temp  = root;
		for(i=0;i<length;++i)
		{
			index = intoint(key[i]);
			if(!temp->children[index])
				return false;
			temp = temp->children[index];	
		}
		return ( temp->isleaf == true);
	}
	
	int main()
    {
    // Input keys (use only 'a' through 'z' and lower case)
        char keys[][8] = {"the", "a", "there", "answer", "any","by", "bye", "their"};
 
        char output[][32] = {"Not present in trie", "Present in trie"};
 
 
        struct trienode *root = getnode();
 
          // Construct trie
        int i;
        for (i = 0; i < 8; i++)
            insert(root, keys[i]);
 
    // Search for different keys
        printf("%s --- %s\n", "the", output[search(root, "the")] );
        printf("%s --- %s\n", "these", output[search(root, "these")] );
        printf("%s --- %s\n", "their", output[search(root, "their")] );
        printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
 
        return 0;
    }
