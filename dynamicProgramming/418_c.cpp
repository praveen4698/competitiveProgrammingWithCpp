#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int ans[27][1501];
    int main()
    {
        int n;
        map<int,int> M;
        scanf("%d",&n);
        string s;
        cin>>s;
        memset(ans,-1,sizeof(ans));
        for(int i=0;i<26;++i)
        {
            for(int j=0;j<n;++j)
            {
                if( s[j]-'a' == i)
                {
                    M[i] = 1;
                    int cont = 1;
                    ans[i][0] = max(ans[i][0],1);
                    for(int k = j+1;k<n;++k)
                    {
                        if( s[k] - 'a' == i)
                        {
                            cont++;
                            ans[i][k-j-cont+1] = max(ans[i][k-j-cont+1],k-j+1);
                        }
                    }

                }
            }
        }
        for(int i=0;i<26;++i)
        {
            if( M[i] == 0)
                ans[i][0] = 0;
            for(int j=1;j<n+1;j++)
            {
                ans[i][j] = max(ans[i][j],ans[i][j-1]+1);
                if( ans[i][j] > n)
                    ans[i][j] = n;
            }
        }
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int a;
            char c;
            scanf("%d %c",&a,&c);
            printf("%d\n",ans[c-'a'][a]);
        }
        return 0;
    }
