#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int n;
    int pos[26];
    memset(pos,0,sizeof(pos));
    S(n);
    int flag = 0;
    int ans = 0;
    int sel = -1;
    int check[30];
    for(int i=0;i<n;++i)
    {
        char a;
        string s;
        cin>>a>>s;
        if( flag == 1)
        {
            if( i < n-1 && a == '!')
                ans++;
            if( i < n-1 && a == '?')
                ans++;
           // cout<<i<<endl;
        }
        else
        {
            if( a == '!')
            {
                memset(check,0,sizeof(check));
                for(auto ss:s)
                {
                    if(check[ss-'a'] == 0)
                    {
                        pos[ss-'a']++;
                        check[ss-'a'] = 1;

                    }
                }
            }
            if( i < n-1 && a == '?')
            {
                for(auto ss:s)
                {
                    pos[ss-'a'] = -1000000;
                }
            }
            if( a == '.')
            {
                for(auto ss:s)
                {
                    pos[ss-'a'] = -1000000;
                }
            }
            int maxi = -1;
            int cont = 0;
            for(auto a:pos)
                maxi = max(a,maxi);
           // cout<<maxi<<endl;
            for(int j=0;j<26;++j)
            {
                if( pos[j] == maxi)
                    cont++;
            }
            if( cont == 1)
            {
                flag = 1;
                for(int j=0;j<26;++j)
                {
                    if( pos[j] == maxi)
                        sel = j;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
