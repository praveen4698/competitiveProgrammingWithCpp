#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int N = 1000001;
    int A[1000001];
    long long int B[100001];
    int main()
    {
        lp( i,1,N+1)
        {
            A[i] = -1;
        }
        for(int i = 2; i*i <= N ; ++i)
        {
            if( A[i] == -1)
            {
                for(int j = 2*i ; j <= N ; j = j + i)
                {
                    A[j] = 1;
                }
            }
        }
        set<long long int > st;
        lp(i,2,N+1)
        {
            if( A[i] == -1)
            {
                //printf("%d\n ",i);
                //if( i == 999983)
                   // printf("uo");
                st.insert((long long int)i * (long long int)(i));
            }
        }

        int n;
        scanf("%d",&n);
        lp(i,0,n)
        {
            cin>>B[i];
        }
        lp(i,0,n)
        {
            if( st.find(B[i]) != st.end() )
                printf("YES\n");
            else
                printf("NO\n");
        }
        return 0;
    }

