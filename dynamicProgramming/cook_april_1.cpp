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
            int a,b;
            int i = 1;
            scanf("%d %d",&a,&b);
            int flag = 0;
            while(1)
            {
                if( i%2 == 1)
                {
                    a = a-i;
                    if( a<0)
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    b = b-i;
                    if( b<0)
                    {
                        flag = 2;
                        break;

                    }
                }
                i++;
                if(flag != 0)
                    break;
            }
            if(flag == 1)
                printf("Bob\n");
            else
                printf("Limak\n");
        }

        return 0;
    }
