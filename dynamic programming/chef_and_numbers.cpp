#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        set<int> S;
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if( S.size() == 0)
                S.insert(x);
            else if( x < *S.begin())
                S.insert(x);
            else if( x > *S.rbegin())
            {
                S.erase(--S.end());
                S.insert(x);
            }
            else if( S.find(x) == S.end())
            {
                auto it = S.upper_bound(x);
                S.erase(--it);
                S.insert(x);
            }
        }
        printf("%d",S.size());
        return 0;
    }
