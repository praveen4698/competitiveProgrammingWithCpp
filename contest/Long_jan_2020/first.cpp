#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int s, a,b,c;
        scanf("%d %d %d %d", &s, &a, &b, &c);
        if ((a+b+c) <= s) {
            printf("1\n");
        }
        else if ( (a+b <= s & c <= s) || (b+c <= s & a <=s) ) {
            printf("2\n");
        }
        else {
            printf("3\n");
        }
    }
    return 0;
}