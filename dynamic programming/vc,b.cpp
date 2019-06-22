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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int n,m,k;
        scan3(n,m,k);
        int x = m-n;
        int left = k-1;
        int right = n-k;
        int height = 1;
        if( x >= 1)
        {
            x = x-1;
            height = height + 1;
        }
        int i = 1;
        int j = 1;
       // printf("%d\n",height);
        while( x >= 0)
        {
            int tempx = min( i ,left);
            i++;
            int tempy = min( j ,right);
            j++;
            if( tempx == left && tempy == right)
            {
                int temp = x/n;
                height = height + temp;
                break;
            }
            else
            {
                x = x-1-tempx-tempy;
                if( x >= 0)
                    height = height + 1;
                //printf("%d\n",height);
            }
        }
        printf("%d\n",height);
        return 0;
    }
