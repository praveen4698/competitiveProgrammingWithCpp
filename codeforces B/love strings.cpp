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
        string s;
        int n,k,A[26];
        cin>>s;
        n = s.length();
        scan(k);
        int maxi = 0;
        lp(i,0,26)
        {
            scan(A[i]);
            if( maxi < A[i])
                maxi = A[i];
        }
        int count = 0;
        lp(i,0,n)
        {
            count = count + (i+1)*(A[s[i]-'a']);
        }
        lp(i,n+1,k+n+1)
        {
            count = count + i*maxi;
        }
        printf("%d\n",count);
        return 0;
    }

