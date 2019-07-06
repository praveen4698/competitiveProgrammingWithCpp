#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define scan(a) scanf("%d",&a)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int dp[1009][1009],cnt[1009][1009];
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        char A[1009],B[1009];
        int k;
        scan(k);
        while(k != 0)
        {
            scanf("%s %s",A,B);
            int l1 = strlen(A);
            int l2 = strlen(B);
            cnt[0][0] = 0;
            lp(i,0,1009)
                dp[0][i] = dp[i][0] = 0;
            lp(i,1,l1+1)
            {
                lp(j,1,l2+1)
                {
                    dp[i][j] = max( dp[i-1][j],dp[i][j-1]);
                    if( A[i-1] == B[j-1])
                        cnt[i][j]= cnt[i-1][j-1] + 1;
                    else
                        cnt[i][j] = 0;
                    if(cnt[i][j] >= k)
                            lp(z,k,cnt[i][j] + 1)
                                dp[i][j] = max(dp[i][j],dp[i-z][j-z]+z);

                }

            }
            printf("%d\n",dp[l1][l2]);
            scan(k);
        }
        return 0;
    }

