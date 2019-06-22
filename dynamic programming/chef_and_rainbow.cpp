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
            int n;
            map<int,int> M1,M2;
            scanf("%d",&n);
            int flag = 0;
            for(int i=0;i<n;++i)
            {
                int a;
                scanf("%d",&a);
                if( a > 7)
                    flag =2;
                else if( a == 7)
                {
                    if( flag == 0)
                        flag = 1;
                }
                else
                {
                    if(flag == 0)
                        M1[a]++;
                    else if(flag == 1)
                        M2[a]++;
                }
            }
            if(flag == 2)
                printf("no\n");
            else
            {
                int flag1= 0;
                for(int i=1;i<7;++i)
                {
                    if(M1[i]!=M2[i])
                        flag1 = 1;
                }
                if( flag1 == 0)
                    printf("yes\n");
                else
                    printf("no\n");
            }
        }
        return 0;
    }
