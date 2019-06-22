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

    int A[1000001];
    int main()
    {
        int n,c,k;
        scan3(n,c,k);
        int wait = -1,cont = 0,ans = 0;
        lp(i,0,n)
            scan(A[i]);
        sort(A,A+n);
        lp(i,0,n)
        {
            int a;
            a = A[i];
            if( wait == -1)
                wait = a;

            //printf("%d\n",wait);
            if( a-wait > k)
            {
                ans++;
                wait = a;
                cont = 1;
            }
            else if( cont+1 == c)
            {
                ans++;
                cont = 0;
                wait = -1;
            }
            else
                cont++;


        }
        if( cont > 0)
        {
            ans++;
        }
        cout<<ans;


        return 0;
    }


