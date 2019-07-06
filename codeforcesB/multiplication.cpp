#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,k;
            cin>>n>>k;
            string s;
            cin>>s;
            for(int i=0;i<k+1;++i)
                s+="0";
            int ans = -1;
            for(int i=0;i<n;++i)
            {
                int temp = 1;
                for(int j=i;j<i+k;++j)
                    temp*=(s[j]-'0');
                ans = max(temp,ans);
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
