#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    int x,y,z,a,b,c;
    ll solve(vector<int> &A)
    {
        ll ans = 0ll;
        ll mini = A[0];

    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {

            cin>>x>>y>>z>>a>>b>>c;
            vector<int> A;
            A.push_back(x);
            A.push_back(y);
            A.push_back(z);
            ll cost = 0ll;
            sort(A.begin(),A.end());
            ll cost2 = solve(A);
            int mini = A[0];
            if(mini%2 == 0)
            {
                ll t1 = 3ll*mini*b/2;
                ll t2 = 1ll*mini*c;
                ll t3 = 3ll*mini*a;
                cost+=min(t1,min(t2,t3));
            }
            else
            {
                ll t1 = 3ll*(mini-1)*b/2;
                ll t2 = 1ll*(mini-1)*c;
                ll t3 = 3ll*(mini-1)*a;
                cost+=min(t1,min(t2,t3));
                t1 = 1ll*c;
                t2 = 1ll*(a+b);
                t3 = 3ll*a;
                cost+=(min(t1,min(t2,t3)));

            }
            ll t1 = mini*1ll*(a+b);
            cost = min(cost,t1);
            A[0]-=mini;
            A[1]-=mini;
            A[2]-=mini;
            t1 = A[1]*b;
            ll t2 = A[1]*a*2ll;
            cost+=min(t1,t2);
            cost+=(1ll*a*(A[2]-A[1]));
            cout<<cost<<endl;
        }
        return 0;
    }
