#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
// prefix of a word means starting from the first letter of the word and size less than the word
// in my code "SET" is not considered as a prefix of the word "SET"
struct node
{
	bool flag;            // flag=1 denotes the end of the string
	node* str[26];        // array of pointers to store the address of the next memory block
};
void insert(node* head, char word[])
{
	for (int i = 0; word[i] != '\0'; i++)
    {
		if (head->str[word[i] - 'a'] == NULL)  // if at a particular stage the desirable letter does not exist
		{
			node* create = (node*)malloc(sizeof(node));    // create a memory block for the new letter and mark it in the str[]
			for (int j = 0; j < 26; j++)
			{
				create->str[j] = NULL;
				create->flag = 0;
			}
			head->str[word[i] - 'a'] = create;     // linking the new node created to the previous node..
			head = create;
		}
		else                                   // if the particular prefix already exist just traverse the trie
		{
			head = head->str[word[i] - 'a'];
		}
	}
	head->flag = 1;                             // denotes the end of the word
}
node* search(node* head,char prefix[])
{
    for(int i=0;prefix[i]!='\0';i++)
    {
        if(head->str[prefix[i]-'a']==NULL)
        {
            return NULL;                       // if the "i" th character of the prefix string does not exist in the trie
        }
        else
        {
            head=head->str[prefix[i]-'a'];     // traversal of the trie
        }
    }
    return head;                               // returning the address of the next memory block after the ending of the prefix word
}
void alphabetical_print(node* start,char prefix[],vector<char>add_after_prefix)
{
    if(start->flag==1 && add_after_prefix.size()!=0)
    {
        cout<<prefix;                                // if the word in the trie ends then display the word
        for(int i=0;i<add_after_prefix.size();i++)
         cout<<add_after_prefix[i];
         cout<<"\n";
    }
   for(int i=0;i<26;i++)
   {
       if(start->str[i]!=NULL)
       {
           add_after_prefix.push_back('a'+i);       // push the letter in the add_after_prefix vector
           alphabetical_print(start->str[i],prefix,add_after_prefix);
           add_after_prefix.pop_back();            // after finishing the particular word remove the last letter and go back to the previous level
                                                   // in the trie and complete the next possible word
       }
   }
   add_after_prefix.pop_back();
}
int main()
{
	int nofwords,nofprefix_words;
		char word[25],prefix[25];
		cout<<"enter the number of words you want to add \n";
	    cin >> nofwords;
	struct node* head = (node*)malloc(sizeof(node));  // intialising the trie with NULL pointers as the trie is empty
	for (int i = 0; i < 26; i++)
    {
		head->str[i] = NULL;
	}
	head->flag = 0;                                   // marking the flag to 0 intially
	for (int i = 0; i < nofwords; i++)
    {
		cin >> word;
		insert(head, word);                           // passing the head of the trie
    }
    cout<<"enter the number of prefix words you want to search for \n";
    cin>>nofprefix_words;
    for(int i=0;i<nofprefix_words;i++)
    {
        cin>>prefix;
        node* temp=search(head,prefix);               // passing the head of the trie
        if(temp!=NULL)
        {
            bool child=false;
            for(int i=0;i<26;i++)
            {
                if(temp->str[prefix[i]-'a']!=NULL)
                {
                  child=true;                         // there exists a word having size greater than the prefix word
                  break;
                }
            }
            if(child==false)
            {
                cout<<"No match.\n"; // adhering to the definition of the prefix i.e."SET" is not considered as a prefix of the word "SET"
            }
            else
            {
                vector<char>add_after_prefix;
                alphabetical_print(temp,prefix,add_after_prefix);
                cout<<"\n";                                          // printing in the alphabetical order
            }
        }
        else
        {
            cout<<"No match.\n";                              // if temp is null then such word doesnt exist in trie
        }
    }
	return 0;
}


