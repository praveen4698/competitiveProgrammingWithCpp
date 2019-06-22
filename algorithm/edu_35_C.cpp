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
    vector<int> A;
    int a,b,c;
    cin>>a>>b>>c;
    A.push_back(a);
    A.push_back(b);
    A.push_back(c);
    sort(A.begin(),A.end());
    if( A[0] == 1)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if( A[0] == 2 && A[1] == 2)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if( A[0] == 3 && A[1] == 3 && A[2] == 3)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    if( A[0] == 2 && A[1] == 4 && A[2] == 4)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}
