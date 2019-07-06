#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;

const int MAX = 10001;
const LL MAX3 = 1000000000001LL;

#define inchar			getchar_unlocked
#define outchar(x)		putchar_unlocked(x)


vector<LL> pbase;

void pre_compute() {
	for(int i = 2; i < MAX; ++i) {
		LL start = 1LL * i * i * i;
		while(start < MAX3) {
			pbase.push_back(start);
			start *= i;
		}
	}
	sort(pbase.begin(), pbase.end());
}

int main() {


	pre_compute();
	int t;
	LL n, ans;
	cin>> t;
	while(t--) {
		cin>>n;
		if (n == 1) puts("INFINITY");
		else {
			ans = (n + 1) / 2;
			printf("%lld\n",ans);
			ans += ((int)sqrt(n)) - ((int)sqrt(n/2));
			printf("%lld\n",ans);
			ans += upper_bound(pbase.begin(), pbase.end(), n) - upper_bound(pbase.begin(), pbase.end(), n / 2);
		//	//int temp =upper_bound(pbase.begin(), pbase.end(), n) - upper_bound(pbase.begin(), pbase.end(), n / 2);
			//printf("%d %d\n",upper_bound(pbase.begin(), pbase.end(), n)- pbase.begin(),upper_bound(pbase.begin(), pbase.end(), n / 2) -pbase.begin());
			//printf("asfa %lld\n",pbase[upper_bound(pbase.begin(), pbase.end(), n)- pbase.begin()]);
			for(int i = 0;i< 15;++i)
            {
                printf("%lld\n",pbase[i]);
            }
		//	printf("%d\n",temp);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
