#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    int t;
    S(t);
    while(t--)
    {
        int i,j;
        int cont1=0,cont2=0;
        S2(i,j);
        while(i!=j)
        {
            if( i > j)
            {
                i/=2;
                cont1++;
            }
            else if( i < j)
            {
                j/=2;
                cont2++;
            }

        }
        cout<<cont1+cont2<<endl;
    }
    return 0;
}
