#include<bits/stdc++.h>

using namespace std;
long long int sum[1000000];

int main() {
    memset(sum, 0ll, sizeof(sum));
    vector<long long int> A;
    int n, q;
    scanf("%d %d", &n, &q);
    sum[0] = 0ll;
    for(int i=1;i<=n;++i){
        long long int a;
        cin>>a;
        if( i == 0) {
            sum[i] = a;
        }
        else {
            sum[i] = sum[i-1] + a;
        }
    }
    while(q--) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", sum[b] - sum[a-1]);
    }
    return 0;
     
}