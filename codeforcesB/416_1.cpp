#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int a,b;
        cin>>a>>b;
        int i = 1;
        int flag = 0;
        while(1)
        {
            if( i%2 == 1)
            {
                a = a-i;
                if( a < 0)
                {
                    printf("Vladik\n");
                    return 0;
                }
            }
            else
            {
                b= b-i;
                if( b < 0)
                {
                    printf("Valera\n");
                    return 0;
                }

            }
            i++;
        }
        return 0;
    }
