#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 2501;
    int A[lim][lim];
    vector<int> temp;
    int len[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,k;
            memset(A,0,sizeof(A));
            scanf("%d %d",&n,&k);
            for(int i=0;i<n;++i)
            {
                scanf("%d",&len[i]);
                for(int j=0;j<len[i];++j)
                {
                    int a;
                    scanf("%d",&a);
                    A[i][a] = 1;
                }
            }
            int ans=0;
            for(int i=0;i<n;++i)
            {
                temp.clear();
                for(int j=1;j<=k;j++)
                {
                    if(A[i][j] == 0)
                        temp.push_back(j);
                }
                if(temp.size() == 0)
                    ans+=(n-i-1);
                else
                {
                    for(int j=i+1;j<n;++j)
                    {
                        if(len[i]+len[j] >= k)
                        {
                            int flag = 0;
                            for(auto v:temp)
                            {
                                if(A[j][v] == 0)
                                {
                                    flag = 1;
                                    break;
                                }
                            }
                            if(flag == 0)
                                ans++;
                        }
                    }
                }
            }
            printf("%d\n",ans);
        }
        return 0;
    }
