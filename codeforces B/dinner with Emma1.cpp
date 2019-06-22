#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;



	int main()
	{
		vi A;
		int n,m;
		cin>>n>>m;
		//A = new vi [n];
		int i,j;
		int min = 0;
		//FOR(i,0,101)
	//	{
	//		A[i] = 0;
	//	}
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				int a;
				cin>>a;
				A.push_back(a);
			}
			vi::iterator temp = min_element(A.begin(),A.end());
			A.clear();
			//cout<<(*temp);
			//printf("\n");
			if ((*temp) > min)
			{
				min = (*temp);
			}
		}
		cout<<min;
		return 0;
	}
