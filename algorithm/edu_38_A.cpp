#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

vector<char> A;
int main()
{
    int n;
    scan(n);
    string S;
    cin>>S;
    map<char,int> M;
    M['a'] = 1;
    M['i'] = 1;
    M['o']  = 1;
    M['e'] = 1;
    M['u'] = 1;
    M['y'] = 1;
    for(int i=0;i<n;++i)
        A.pb((char)S[i]);
    vector<char> temp;
    for(int k=0;k<100;++k)
    {
        for(auto a: A )
            temp.pb(a);
        int flag = -1;
        for(int i=1;i<temp.size();++i)
        {
            if( M[temp[i]] == 1 && M[temp[i-1]] == 1)
                flag = i;
        }
        A.clear();
        for(int i=0;i<temp.size();++i)
        {
            if( flag != i)
                A.pb(temp[i]);
        }
        temp.clear();
    }
    for(auto a:A)
        cout<<a;
    return 0;
}


