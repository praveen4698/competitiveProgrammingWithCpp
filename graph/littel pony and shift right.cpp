#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
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

    int A[200001];
    int main()
    {
        int n;
            scan(n);
        lp(i,0,n)
            scan(A[i]);
        int maxi = 0 ,value = 0;
        lp(i,0,n)
            if(A[i]>=maxi)
                maxi = A[i],value = i;
        int flag = 0;
        //printf("%d\n",value);
        if( value== n-1 && A[0] == maxi)
            {
                lp(i,0,n)
                {
                    if( A[i] == maxi)
                        value = i;
                    else
                        break;
                }
            }

        lp(i,0,n-1)
            if( A[(value+i+1)%n]> A[(value+i+2)%n])
                    flag = 1;

        if(flag == 1)
            printf("-1");
        else
            printf("%d",n-value-1);
        return 0;
    }

