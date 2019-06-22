#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int n =10000;
    bool prime[10001]
    void SieveOfEratosthenes()
    {

        memset(prime, true, sizeof(prime));
        for (int p=2; p*p<=n; p++)
        {

            if (prime[p] == true)
            {

                for (int i=p*2; i<=n; i += p)
                    prime[i] = false;
            }
        }


    }
    void precompute()


    int main()
    {

        return 0;
    }

