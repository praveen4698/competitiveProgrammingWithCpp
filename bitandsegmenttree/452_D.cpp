#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 2e5+10;
vector<int> add[lim],rem[lim];
map<char,int> M;
int main()
{
    int n,q;
    string s;
    scanf("%d %d",&n,&q);
    cin>>s;
    while(q--)
    {
        int a,b;
        char c;
        scanf("%d %d",&a,&b);
        cin>>c;
        add[a-1].push_back(c);
        rem[b].push_back(c);
    }
    for(int i=0;i<n;++i)
    {
        for(auto a:add[i])
        {
            M[a]++;
        }
        for(auto a:rem[i])
            M[a]--;
        if( M[s[i]] == 0)
            cout<<s[i];
    }
    return 0;
}
