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
unordered_map<int,pair<int,int> > M;
set<int> S;
vector<int> A;
int main()
{
    int t;
    scan(t);
    int xx = 1;
    while(t--)
    {
        int n;
        scan(n);
        M.clear();
        A.clear();
        S.clear();
        for(int i=0;i<n;++i)
        {
            int a;
            scan(a);
            A.pb(a);
            M[a].first = 0;
            M[a].second = 0;
        }
        for(int i=0;i<n;++i)
        {
            S.insert(A[i]);
            if( i%2 == 0)
                M[A[i]].first+=1;
            else
                M[A[i]].second+=1;
        }
        int last = 0;
        int flag = 0;
        int ans = -1;
        for(auto i=S.begin();i!=S.end();++i)
        {
            int a = *i;
            while(M[a].first > 0 || M[a].second > 0)
            {
                if( last%2 == 0)
                {
                    if( M[a].first > 0)
                    {
                        last++;
                        M[a].first--;
                    }
                    else
                    {
                        flag = 1;
                        ans = last ;
                        break;
                    }
                }
                else if(last%2 == 1)
                {
                    if( M[a].second > 0)
                    {
                        last++;
                        M[a].second--;
                    }
                    else
                    {
                        flag = 1;
                        ans = last ;
                        break;
                    }
                }

            }
            if(flag == 1)
                break;
        }

        if( flag == 0)
            printf("Case #%d: OK\n",xx);
        else
            printf("Case #%d: %d\n",xx,ans);
        xx++;


    }
    return 0;
}


