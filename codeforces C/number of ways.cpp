#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
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

    long long int A[500001],cnt[500001],tempsum[500001];
    int main()
    {
        int n;
        long long int re = 0;
        long long int Sum=0;
        scan(n);
        lp(i,0,n)
        {
            cin>>A[i];
            Sum = Sum + A[i];
        }
        if( Sum%3 != 0 || n <= 2)
        {
            printf("0");
            return 0;
        }
        long long int temp =0;
        lpr(i,n-1,0)
        {
            temp = temp + A[i];
            if( temp == Sum/3)
                cnt[i] = 1;
            else
                cnt[i] = 0;
        }
        tempsum[n-1] = cnt[n-1];
        lpr(i,n-2,0)
            tempsum[i] = tempsum[i+1] + cnt[i];
        temp = 0;
       // lp(i,0,n)
        //    printf("%d %d\n",cnt[i],tempsum[i]);
        lp(i,0,n-2)
        {
            temp = temp + A[i];
            if( temp == Sum/3)
                re = re + (long long int)tempsum[i+2];
        }
        cout<<re;

        return 0;
    }

