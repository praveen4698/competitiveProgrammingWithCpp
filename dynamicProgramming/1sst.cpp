#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            map<string,int> M;
            for(int i=0;i<4;++i)
            {
                string s;
                int a;
                cin>>s>>a;
                M[s] =a;
            }
            if( M["RealMadrid"] < M["Malaga"] && M["Barcelona"] > M["Eibar"] )
            {
                printf("Barcelona\n");

            }
            else
            {
                printf("RealMadrid\n");
            }
        }
        return 0;
    }
