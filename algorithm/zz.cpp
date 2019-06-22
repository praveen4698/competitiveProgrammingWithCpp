
#include<iostream>
using namespace std;
 
void getZarr(string str, int Z[]);
 

int  search(string text, string pattern)
{
    int count = 0;
    string concat = pattern + "$" + text;
    int l = concat.length();
    int a = 0;
  
    int Z[l];
    getZarr(concat, Z);
 
    
    for (int i = pattern.length(); i < l; ++i)
    {
       
        if (Z[i] == pattern.length() && i-a > pattern.length())
           {
		   count++;
		   a = i;}
    }
    return count;
}
 

void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
 
    
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        
        if (i > R)
        {
            L = R = i;
 
          
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
         
            k = i-L;
 
           
            if (Z[k] < R-i+1)
                 Z[i] = Z[k];
 
            else
            {
            
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}
 

int main()
{
    string text;
    cin >> text;
    string pattern ;
    cin >> pattern;
    int count = search(text, pattern);
    cout << count;
    return 0;
}
