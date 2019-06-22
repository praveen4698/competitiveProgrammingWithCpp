#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    map<string,vector<string> > M;
    map<string,set<string> > ans;
    set<string> A;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        string s;
        int a;
        cin>>s>>a;
        A.insert(s);
        for(int j=0;j<a;++j)
        {
            string t;
            cin>>t;
            M[s].push_back(t);
        }

    }
    for(auto a:A)
    {
        for(int i=0;i<M[a].size();++i)
        {
            int flag = 0;
            for(int j=0;j<M[a].size();++j)
            {
                if( i==j)
                    continue;
                string b = M[a][i];
                string c = M[a][j];
                if( b.length() >= c.length())
                    continue;
                int t = b.length()-1;
                int x = c.length()-1;
                int cont = 0;
                while(t>=0)
                {
                    if( b[t] == c[x])
                        cont++;
                    t--;
                    x--;
                }
                if( cont == b.length())
                    flag = 1;
            }
            if( flag == 0)
                ans[a].insert(M[a][i]);
        }
    }
    cout<<A.size()<<endl;
    for(auto a:ans )
    {
        cout<<a.first<<" "<<a.second.size()<<" ";
        for(auto x:a.second)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
