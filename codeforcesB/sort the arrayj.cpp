#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define si 123456
typedef map<int,int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int A[si],B[si];
    int main()
    {

        int n;
        scanf("%d",&n);
        lp(i,0,n)
        {
            scanf("%d",&A[i]);
            B[i] = A[i];
        }
        mii mp;
        sort(B,B+n);
        lp(i,0,n)
            mp[B[i]] = i;
        lp(i,0,n)
            A[i] = mp[A[i]];
        int L = -1;
        lp(i,0,n)
            if(A[i] != i)
            {
                L = i;
                break;
            }
        int R = -1;
        lpr(i,n-1,0)
            if(A[i] != i)
            {
                R = i;
                break;
            }
        if( L == -1 || R == -1)
            printf("yes\n1 1\n");
        else
        {
            reverse(A+L,A+R+1);
            bool re = true;
            lp(i,0,n)
                if( A[i] != i )
                    re = false;
            if(re)
                printf("yes\n%d %d\n",L+1,R+1);
            else
                printf("no\n");

        }



        return 0;
    }

