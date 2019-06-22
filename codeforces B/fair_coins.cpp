#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9+7;
    struct Matrix
    {
        ll a,b,c,d;
        Matrix(ll a1,ll b1,ll c1,ll d1)
        {
            a = a1;
            b = b1;
            c = c1;
            d = d1;
        }
    };
    Matrix MUL(Matrix A,Matrix B)
    {
        ll a1 = (A.a*B.a + A.b*B.c)%mod;
        ll b1 = (A.a*B.b + A.b*B.d)%mod;
        ll c1 = (A.c*B.a + A.d*B.c)%mod;
        ll d1 = (A.c*B.b + A.d*B.d)%mod;
        return Matrix(a1,b1,c1,d1);
    }
    Matrix power(Matrix A,int n)
    {
        if( n == 0)
            return A;
        if( n == 1)
            return A;
        Matrix t = power(A,n/2);
        t = MUL(t,t);
        if( n&1 == 1)
            return MUL(t,A);
        else
            return t;
    }
    int main()
    {
        Matrix A = Matrix(2LL,2LL,1LL,0LL);
        int t;
        scanf("%d",&t);
        while(t--)
        {
            ll n;
            cin>>n;
            if( n == 1)
            {
                printf("1\n");
                continue;
            }
            if( n == 2)
            {
                printf("3\n");
                continue;
            }
            Matrix ans = power(A,n-2);
            cout<<(ans.a*3+ans.b)%mod<<"\n";

        }
        return 0;
    }
