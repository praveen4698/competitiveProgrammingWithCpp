#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int A,B;
        int mini1 ;
        int mini2;
        scanf("%d %d",&A,&B);
        int a;
        cin>>a;
        mini1 = a;
        int N[10] ,M[10];
        for(int i=0;i<10;++i)
        {
            N[i] = 0;
            M[i] = 0;
        }
        N[a] = 1;
        for(int i=0;i<A-1;++i)
        {
            cin>>a;
            mini1 = min(mini1,a);
            N[a] = 1;
        }
        cin>>a;
        mini2 = a;
        M[a] = 1;
        for(int i=0;i<B-1;++i)
        {
            cin>>a;
            mini2 = min(mini2,a);
            M[a] =1;
        }
        for(int i=1;i<10;++i)
        {
            if(N[i] == 1&& M[i] == 1)
            {
                printf("%d",i);
                return 0;
            }
        }
        if( mini1 == mini2)
        {

            printf("%d",mini2);
            return 0;
        }
        printf("%d%d",min(mini1,mini2),max(mini1,mini2));

        return 0;
    }
