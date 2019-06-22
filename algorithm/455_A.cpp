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
    string A,B;
    vector<char> ans;
    cin>>A>>B;
    ans.push_back((char)A[0]);
    for(int i=1;i<A.length();++i)
    {
        if( A[i]-'a' < B[0]-'a')
            ans.push_back((char)A[i]);
        else
            break;
    }
    for(auto a:ans)
        cout<<a;
    cout<<B[0];

    return 0;
}
