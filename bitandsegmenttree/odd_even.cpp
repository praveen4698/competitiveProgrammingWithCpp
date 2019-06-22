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
const int lim = 1e5+10;
int bit[lim+1];
void update(int x, int val)
{
      for(; x <= lim; x += x&-x)
        bit[x] += val;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bit[x];
     return sum;
}
int A[lim];
int main()
{
    int n,q;
    S(n);
    for(int i=1;i<=n;++i)
    {
        S(A[i]);
        A[i] = A[i]%2;
        update(i,A[i]);
    }
    S(q);
    while(q--)
    {
        int a,b,c;
        S3(a,b,c);
        if( a == 0)
        {
            if( c%2 == 1 && A[b]%2 == 0)
            {
                update(b,1);
                A[b] = 1;
            }
            if( c%2 == 0 && A[b]%2 == 1)
            {
            //cout<<"asf"<<endl;
                update(b,-1);
                A[b] = 0;
            }
        }
        else if( a == 1)
        {
            P(c-b+1-(query(c)-query(b-1)));
        }
        else
            P(query(c)-query(b-1));
    }
    return 0;
}
