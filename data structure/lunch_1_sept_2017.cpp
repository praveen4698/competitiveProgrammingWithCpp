#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        map<string,int> M;
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            M.clear();
            for(int i=0;i<n;++i)
            {
                string a;
                cin>>a;
                M[a]++;
            }
            if( M["cakewalk"] >= 1 && M["simple"] >= 1 && M["easy"] >= 1 && (M["easy-medium"] >= 1 || M["medium"] >= 1) && (M["medium-hard"] >= 1 || M["hard"] >= 1))
            {
                printf("Yes\n");
            }
            else
                printf("No\n");
        }
        return 0;
    }
