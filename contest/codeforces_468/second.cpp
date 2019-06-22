#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

vector<int> A[256];
int main()
{
    int n;
    int a,b;
    scan3(n,a,b);
    if(  a > b)
        swap(a,b);
    for(int i=0;i<n;++i)
        A[1].pb(i+1);
    int level = 1;
    while(1)
    {
        for(int i=0;i<A[level].size();i = i+2)
        {
            if( A[level][i] == a && A[level][i+1] == b)
            {
                if( A[level].size() == 2)
                    cout<<"Final!"<<endl;
                else
                    cout<<level<<endl;
                return 0;
            }
            if( A[level][i] == a || A[level][i] == b)
                    A[level+1].pb(A[level][i]);
            else
                A[level+1].pb(A[level][i+1]);


        }
        level++;
    }
    return 0;
}


