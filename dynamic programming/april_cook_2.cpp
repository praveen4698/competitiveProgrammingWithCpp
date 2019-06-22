#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    long long int conta[1000001],contb[1000001];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,m;
            scanf("%d %d",&n,&m);
            string S;
            cin>>S;
            int cont ;
            if( S[n-1] == 'b')
            {

                contb[n-1] = 1;
            }
            else
            {
                contb[n-1] = 0;
            }
            for(int i = n-2;i>= 0;--i)
            {
                if( S[i] == 'b')
                    contb[i] = 1+contb[i+1];
                else
                    contb[i] = contb[i+1];
            }
            long long int conti = 0;
            for(int i = 0;i<n;++i )
            {
                if( S[i] == 'a')
                {
                    conti = conti + (long long int)((m)*((m-1)*contb[0]+contb[i]+contb[i]))/2;
                }
            }
            printf("%lld\n",conti);
        }
        return 0;
    }
