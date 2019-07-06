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

    bool check(int n)
    {
        for(int i = 2; i*i <= n;++i)
        {
            if( n%i == 0)
                return false;
        }
        return true;
    }
    int main()
    {
        int n;
        scan(n);
        if( n== 1)
        {

           printf("3");
           return 0;
        }
        for(int i = 1;i<= 1000;++i)
        {
            if( check((n*i)+1) == false)
            {
                printf("%d",i);
                break;
            }
        }
        return 0;
    }
