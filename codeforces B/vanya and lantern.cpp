#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[1234];
    int main()
    {
        int n,d;
        scanf("%d %d",&n,&d);
        lp(i,0,n)
            scanf("%d",&A[i]);
        sort(A,A+n);
        A[n] = d;
        float count = (float)(A[0]);
        lp(i,1,n)
        {
            float temp = (float)(A[i] - A[i-1])/2;
            if( temp > count)
                count = temp ;
        }
        float temp = (float)(A[n] - A[n-1]);
        if( temp > count )
            count = temp;
        printf("%.10f",count);

        return 0;
    }
