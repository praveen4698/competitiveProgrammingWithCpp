#include<bits/stdc++.h>

using namespace std;

int main() {
    long long int t;
    scanf("%lld", &t);
    while(1) {
        printf("%lld ", t);
        if( t== 1ll) {
            break;
        }
        if(t&1) {
            t = 3ll*t + 1ll;
        }
        else{
            t = t/2ll;
        }

    }
}