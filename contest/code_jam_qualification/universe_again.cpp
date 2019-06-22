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

int st[34];
int main()
{
    int t;
    scan(t);
    int xx = 1;
    while(t--)
    {
        int d;
        string S;
        cin>>d>>S;
        int sum = 0;
        int r = 1,n = S.length();
        for(int i=0;i<n;++i)
        {
            if(S[i] == 'S')
            {
                st[i] = r;
                sum+=r;
            }
            else
            {
                st[i] = 0;
                r = r*2;
            }
        }
        if( sum <= d)
        {
            printf("Case #%d: 0\n",xx);
            xx++;
            continue;
        }
        int flag = 0;
        int ans = 0;
        while(1)
        {
            int maxi = 1;
            int e = -1;
            for(int i=1;i<n;++i)
            {
                if( S[i-1] == 'C' && S[i] == 'S' && st[i] > maxi)
                {
                    maxi = st[i];
                    e = i;
                }
            }
            if( maxi == 1)
                break;
            st[e] = st[e]/2;
            sum-=st[e];
            swap(S[e],S[e-1]);
            swap(st[e],st[e-1]);
            ans++;
            if( sum <= d)
            {
                flag = 1;
                break;
            }
        }
        if( flag == 0)
        {
            printf("Case #%d: IMPOSSIBLE\n",xx);

        }
        else
        {
            printf("Case #%d: %d\n",xx,ans);

        }
        xx++;
    }
    return 0;
}


