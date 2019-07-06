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
		string str1;
		cin>>str1;
		string str2(str1);
		reverse(str2.begin(),str2.end());
		cout<<(str1 + str2);
		return 0;
	}
