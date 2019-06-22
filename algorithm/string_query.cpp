#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, splay_tree_tag, tree_order_statistics_node_update>

ordered_set A[30];
int main()
{


    string S;
    cin>>S;
    int n = S.length();
    for(int i=0;i<n;++i)
    {
        A[S[i]-'a'].insert(i);
    }
    for(int i=0;i<30;++i)
    {
        A[i].insert(INF);
    }
    int m;
    scan(m);
    n = n-m;
    while(m--)
    {
        int k;
        char a;
        cin>>k>>a;
        A[a-'a'].erase(*A[a-'a'].find_by_order(k-1));
    }

    vector<char> ans;
    for(int i=0;i<n;++i)
    {
        int mini = INF;
        int value = -1;
        for(int j=0;j<26;++j)
        {
            if( (*A[j].find_by_order(0)) < mini )
            {
                mini = (*A[j].find_by_order(0));
                value = j;
            }
        }
        ans.pb((char)(value + 'a'));
        A[value].erase(*A[value].find_by_order(0));
    }
    for(auto a:ans)
        cout<<a;
    cout<<endl;
    return 0;
}


