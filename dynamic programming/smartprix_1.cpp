#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vector<string> ans;
    int main()
    {
        string A;
        queue<char> S;
        getline(cin,A);
        int n = A.length();
        int cont = 0;
        int cap = 0;
        int currow = 0;
        int curcol = 0;
        string sss;
        ans.push_back(sss);
        for(int i=0;i<n;++i)
        {
            //cout<<"yo";
            if(A[i] == '#')
            {
                string s;
                ans.push_back(s);
                for(int k=ans.size()-1;k>currow+1;--k)
                {
                    ans[k] = ans[k-1];
                }
                if(curcol != ans[currow].size())
                {
                    stack<char> S;
                    for(int k=ans[currow].size()-1;k>=curcol;--k)
                    {
                        S.push((char)ans[currow][k]);
                        ans[currow].pop_back();
                    }
                    ans[currow+1] = "";
                    while(!S.empty())
                    {

                        ans[currow+1].push_back(S.top());
                        S.pop();
                    }
                }

                curcol = 0;
                currow+=1;
            }
            else if( A[i] == '@')
            {
                if(cap == 0)
                    cap = 1;
                else
                    cap = 0;
            }
            else if( A[i] == '<')
            {
              //  printf("<,");

                if( curcol == 0 && currow == 0)
                {
                    continue;
                }
                else if( curcol == 0 )
                {
                    curcol = ans[currow-1].size();
                    currow--;
                }
                else
                    curcol--;
               // printf("%d %d\n",currow,curcol);
            }
            else if( A[i] == '>')
            {
                if(curcol == ans[currow].size() && currow == ans.size()-1)
                    continue;
                else if( curcol == ans[currow].size())
                {
                    currow++;
                    curcol = 0 ;
                }
                else
                {
                    curcol++;
                }

            }
            else if( A[i] == '/')
            {
                if( curcol == 0 && currow == 0 )
                {
                    continue;
                }
                else if( curcol == 0)
                {
                    curcol = ans[currow-1].size();
                    ans[currow-1]+=ans[currow];
                    for(int k=currow;k<ans.size()-1;++k)
                        ans[k] = ans[k+1];
                   // maxi--;
                    currow--;
                    ans.pop_back();
                }
                else
                {
                    if( curcol == ans[currow].size())
                    {

                       ans[currow].pop_back();
                       curcol--;
                    }
                    else
                    {
                        stack<char> S;
                        for(int k=ans[currow].size()-1;k>=curcol;--k)
                        {
                            S.push(ans[currow][k]);
                            ans[currow].pop_back();
                        }
                        ans[currow].pop_back();
                        curcol--;
                        while(!S.empty())
                        {
                            ans[currow].push_back(S.top());
                            S.pop();
                        }
                    }
                }
            }
            else if( A[i] == '?')
            {

                if( currow == ans.size()-1)
                {
                    continue;
                }
                if( i < n-1 && A[i+1] == '?')
                    continue;
                else
                {
                    int j = i;
                    while(A[j] == '?' )
                    {
                        currow++;
                        j--;
                    }
                    if( currow > ans.size()-1)
                        currow = ans.size()-1;
                    if( curcol > ans[currow].size())
                        curcol = ans[currow].size();

                }
            }
            else if( A[i] == '^' )
            {

                if( currow == 0)
                    continue;
                else if( i < n-1 && A[i+1] == '^')
                {
                    continue;
                }
                else
                {
                    int j = i;
                    while(A[j] == '^')
                     {
                         currow--;
                         j--;
                     }
                     if(currow < 0)
                        currow = 0;
                    if( curcol > ans[currow].size())
                        curcol = ans[currow].size();

                }
            }
            else
            {
               // cout<<"yo";
                char value ;
                if( cap == 1)
                {
                    if( A[i] - 'a' >= 0 && A[i]-'a' < 26)
                    {
                        value = (char)(A[i]-'a'+'A');
                    }
                    else
                        value = (char)(A[i]);
                }
                else
                    value = (char)A[i];
               // cout<<value<<"\n";
                if( curcol == ans[currow].size())
                {
                    curcol++;
                    ans[currow].push_back(value);
                }
                else
                {
                    stack<char> Q;
                    for(int k= ans[currow].size()-1;k>=curcol;k--)
                    {
                        Q.push(ans[currow][k]);
                        ans[currow].pop_back();
                    }
                    ans[currow].push_back(value);
                    curcol++;
                    while(!Q.empty())
                    {
                        ans[currow].push_back(Q.top());
                        Q.pop();
                    }
                }
            }
        }
        for(int i=0;i<ans.size();++i)
        {
            if( ans[i].size() > 0)
                cout<<ans[i];
            if( i != ans.size() - 1) printf("\n");
        }
        return 0;
    }
