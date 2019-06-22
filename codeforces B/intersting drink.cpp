#include "bits/stdc++.h"
using namespace std;
#define FOR(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))

static const int INF = 0x3f3f3f3f; 
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi;
typedef pair<int, int> pii; 
typedef vector<pair<int, int> > vpii;
typedef long long ll;


    int main()
	{
	    int i,n;
	    scanf("%d",&n);
	    int A[n];
	    FOR(i,0,n)
	    {
	    	scanf("%d",&A[i]);
		}
		sort(A,A+n);
		int q;
		scanf("%d",&q);
		FOR(i,0,q)
		{
			int y;
			scanf("%d",&y);
			int ans = upper_bound(A,A + n,y) - A;
			printf("%d\n",ans);
			
		}
		
	
	
		return 0;
    }
