#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        vector<string> A;
        map<int,int> label;
        map<string,int> variable;
        int prev = -1;
        string s;
        while(1)
        {
           // printf("sfas0");
            if( cin.fail())
                break;
           getline(cin,s);
            if(s[0] == '\0')
                break;
            string t;
            for(int i=0;i<s.size()+1;++i)
            {
                if(i == s.size() || s[i] == ' ')
                {
                    A.push_back(t);
                    t.clear();
                }
                else
                    t.push_back((char)s[i]);

            }
        }
        int n = A.size();
        for(int i=0;i<n;++i)
        {
            if( A[i] == "LABEL")
            {
                int temp = 0;
                for(int j=0;j<A[i+1].length();++j)
                {
                    temp = temp*10 + (int)(A[i+1][j] - '0');
                }

                label[temp] = i+2;

            }
            if( A[i] == "SET")
            {
                variable[A[i+1]] = 0;
            }
           // cout<<A[i];
           // printf(" %d\n",i);
        }

        //return 0;
        int cont = 0;
        int i = 0;
        while(1)
        {
            if(cont > 30)
                break;
            cont++;
          //  cout<<A[i];
          //  printf(" %d\n",i);

            if( A[i].compare("EXIT") == 0)
                return 0;
            else if( A[i].compare("LABEL") == 0)
            {
                i+=2;
                continue;
            }
            else if(A[i].compare("END") == 0)
            {
                i++;
                continue;
            }
            else if( A[i].compare("SET") == 0)
            {
                int temp = 0;
                i++;
                for(int j=0;j<A[i+1].length();++j)
                {
                    temp = temp*10 + (int)(A[i+1][j]-'0');
                }
                variable[A[i]] = temp;
                i++;
                i++;
            }
            else if( A[i].compare("ECHO") == 0)
            {
                printf("%d\n",variable[A[i+1]]);
                i++;
                i++;
            }
            else if( A[i].compare("CONTINUE") == 0)
            {
                i = prev;
            }
            else if( A[i].compare("IF") == 0)
            {
                prev = i;
                int temp = 0;
                i++;
                for(int j=0;j<A[i+1].length();++j)
                {
                    temp = temp*10 + (int)(A[i+1][j]-'0');
                }
                if( variable[A[i]] == temp)
                {
                    i++;
                    i++;
                }
                else
                {
                    while(A[i].compare("END") != 0)
                        i++;

                    i++;
                }
            }
            else if( A[i].compare("GOTO") == 0)
            {
                int temp = 0;
                for(int j=0;j<A[i+1].length();++j)
                {
                    temp = temp*10 + (int)(A[i+1][j]-'0');
                }
                i = label[temp];
              //  i++;
            }
            else if( A[i].compare("ADD") == 0)
            {
                int value1 = 0;
                int value2 = 0;
                if( A[i+1][0]-'a' >= 0 && A[i+1][0]-'a' < 26 )
                    value1 = variable[A[i+1]];
                else
                {
                    int temp = 0;
                    for(int j=0;j<A[i+1].length();++j)
                    {
                        temp = temp*10 + (int)(A[i+1][j]-'0');
                    }
                    value1 = temp;
                }
                i++;
                if( A[i+1][0]-'a' >= 0 && A[i+1][0]-'a' < 26 )
                    value2 = variable[A[i+1]];
                else
                {
                    int temp = 0;
                    for(int j=0;j<A[i+1].length();++j)
                    {
                        temp = temp*10 + (int)(A[i+1][j]-'0');
                    }
                    value2 = temp;
                }
                i++;
                i++;
                variable[A[i]] = value1 + value2;
                i++;
            }
        }
        return 0;
    }
