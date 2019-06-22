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
    int v1,v2,v3,vm;
    cin>>v1>>v2>>v3>>vm;
    for(int i=1;i<=100;++i)
    {
        if( 2*v3 >= i && v3 <= i && 2*vm >= i && vm <= i  )
        {
            if( i < v2)
            {
                cout<<v1<<endl<<v2<<endl<<i<<endl;
                return 0;
            }
            else
            {
                if( 2*v2 >= (i+1) && v2 <= (i+1) && 2*v1 >= (i+2) && v1 <= (i+2))
                {
                    cout<<(i+2)<<endl<<(i+1)<<endl<<i<<endl;
                    return 0;
                }
            }

        }
    }
    cout<<"-1"<<endl;

    return 0;
}
