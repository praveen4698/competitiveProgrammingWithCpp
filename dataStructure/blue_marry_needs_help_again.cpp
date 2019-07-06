#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    multiset<int> S;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,k;
            scanf("%d %d",&n,&k);
            S.clear();
            int deckey = 0;
            int cont = 0;
            while(n--)
            {
                char a;
                int b;
                cin>>a;
                scanf("%d",&b);

                if(a == 'I')
                {
                   // printf("yo\n");
                    if(b >= k)
                        S.insert(b+deckey-k);
                }
                else if( a == 'A')
                {
                    deckey-=b;
                }
                else if( a == 'S')
                {
                    deckey+=b;
                    for(auto it = S.begin(); it!= S.end();)
                    {
                        if( (*it) - deckey < 0)
                        {
                           // printf("ee\n");
                            cont++;
                            it = S.erase(it);
                        }
                        else
                            break;
                    }
                }
                else
                {
                    if( b <= S.size())
                      {
                          multiset<int>::iterator it = S.begin();
                          advance(it,S.size()-b);
                          printf("%d\n",(*it)+k-deckey );
                      }
                    else
                        printf("-1\n");
                }
               // printf("deckey = %d\n",deckey);
            }
            printf("%d\n",cont);
        }
        return 0;
    }
