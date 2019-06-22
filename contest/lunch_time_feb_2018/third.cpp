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


int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int N,q;
        scan2(N,q);
        string S;
        cin>>S;
        vector<int> ans;
        while(q--)
        {
            int n,k;
            scan2(n,k);
            //int ans =0;
            int ret = -1;
            ans.clear();
            for(int i=0;i<n;++i)
            {
                int cont = 0;
                for(int j=0;j<n-i;++j)
                {
                    if( S[j] == S[j+i])
                        cont++;
                    else
                        break;
                }
                if( cont == n-i)
                    ans.pb(n-i);

            }
            sort(all(ans));
            if(ans.size() >= k)
                cout<<ans[k-1]<<endl;
            else
                cout<<"-1"<<endl;
        }
    }
    return 0;
}


