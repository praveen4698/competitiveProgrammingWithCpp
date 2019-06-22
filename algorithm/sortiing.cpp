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
struct comp {
        bool operator() (const int& lhs, const int & rhs) const
            {return lhs>rhs;}
        };
int main()
{
    int A[50];
    for(int i=0;i<5;++i)
        cin>>A[i];
    sort(A,A+5,comp() );
    for(int i=0;i<5;++i)
        cout<<A[i]<<" ";
    return 0;
}
