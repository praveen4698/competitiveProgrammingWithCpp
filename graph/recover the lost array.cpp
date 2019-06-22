#include<bits/stdc++.h>
using namespace std;

    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            long long int n,o,e;
            cin>>n>>e>>o;
            if( o == 0)
            {
                for(int i =0;i<n;++i)
                    printf("0 ");
                printf("\n");
                continue;
            }
            long long int no_o;
            long long int no_e = no_o = -1;
            for(int i = 1;i <= sqrt(o);++i)
            {
                if( o%i == 0 && (i+o/i) == n+1)
                {
                    no_e = o/i;
                    no_o = i;
                }
            }
            if(no_e == -1)
                printf("-1\n");
            else
            {
                for(int i = 0;i< no_e-1;++i)
                    printf("0 ");
                printf("1 ");
                for(int i = 0;i< no_o-1;++i)
                    printf("0 ");

                printf("\n");
            }
        }
        return 0;
    }
