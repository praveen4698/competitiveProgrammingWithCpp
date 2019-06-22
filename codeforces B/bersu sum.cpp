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


    int main()
    {
        int n,m,A[101],B[101];
        scan(n);
        lp(i,0,n)
            scan(A[i]);
        scan(m);
        lp(i,0,m)
            scan(B[i]);
        sort(A,A+n);
        sort(B,B+m);
        int i=0,j=0,count=0;
        while(i<n && j<m)
        {
            if( (A[i] <= B[j]+1) && ( A[i] >= B[j] - 1) )
                j++,i++,count++;
            else if( A[i] < B[j])
                i++;
            else
                j++;
        }
        printf("%d",count);
        return 0;
    }

