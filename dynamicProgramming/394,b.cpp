#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[101],B[101],sum1[101],sum2[101];
    int main()
    {
        int n,k;
        scan2(n,k);
        lp(i,0,n)
            cin>>A[i];
        lp(i,0,n)
            cin>>B[i];

        sum1[0] = A[0] + k - A[n-1];
        sum2[0] = B[0] + k - B[n-1];
        lp(i,1,n)
        {
            sum1[i] = A[i] - A[i-1];
            sum2[i] = B[i] - B[i-1];
        }
       // lp(i,0,n)
       //     printf("%d ",sum1[i]);
       // lp(i,0,n)
       //     printf("\n%d ",sum2[i]);

        int flag = 0;
        lp(i,0,n)
        {
            lp(j,0,n)
            {
                if( sum1[i] == sum2[j])
                {
                    int counti = 0;
                    lp(k,0,n)
                    {
                        if( sum1[(k+i)%n] == sum2[(j+k)%n])
                            counti = counti + 1;
                    }
                    if( counti == n)
                        flag = 1;
                }

            }
        }

        if( flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }
