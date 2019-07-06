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
    const int lim = 2e5 + 10;
    int A[lim];
    vi T;
    int main()
    {
        int n,k,temp=0 ,re= 0,last = 0;
        scan2(n,k);
        lp(i,0,n)
        {
            scan(A[i]);
            if( A[i] < 0)
                temp++;
        }
        if( temp > k)
        {
            printf("-1");
            return 0;
        }
        if( temp == 0)
        {
            printf("0");
            return 0;
        }
        re = k-temp;
        int ans = 2*(temp);
        lp(i,0,n)
        {
            if( A[i] < 0)
            {
                if( last == 0)
                {
                    last = i+1;
                }
                else
                {
                    T.pb(i - last);
                    last = i + 1;
                }
            }
        }
        sort( T.begin(),T.end());
        vi::iterator it;
        for( it = T.begin(); it != T.end(); it++)
        {
            //printf("%d %d\n",re,*it);
            if( re >= *it)
            {
                ans = ans - 2;
                re = re - *it;
            }
        }
        if( n-last <= re)
            ans = ans -1;

        printf("%d",ans);
        return 0;
    }
