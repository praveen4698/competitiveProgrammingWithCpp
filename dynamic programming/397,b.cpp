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

    const int lim = 1e5 +10;
    int A[lim];
    int main()
    {
        int n;
        scan(n);
        lp(i,0,n)
            scan(A[i]);
        sort(A,A+n);
        int flag = 0;
        //printf("%d",n);
        lp(i,2,n)
        {
           // printf("%d %d %d \n",A[i],A[i-1],A[i-2]);
            if( A[i] < A[i-1] + A[i-2])
            {
                flag = 1;
                break;
            }
        }
        if( flag == 1)
            printf("YES");
        else
            printf("NO");
        return 0;
    }
