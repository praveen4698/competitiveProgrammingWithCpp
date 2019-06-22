#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 2e5+10;
int on[lim];
vector<int> A;
set<int> s;
int main()
{
    memset(on,1,sizeof(on));
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;++i)
    {
        int a;
        scanf("%d",&a);
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    if( k == 1)
    {
        printf("%d\n",n);
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        while((s.size() > 0) && (A[i]-(*(s.begin()))) >= m)
        {
            s.erase(s.begin());
        }
        if(s.size() >= k-1)
            on[i] = 0;
        else
            s.insert(A[i]);
    }
    int cont = 0;
    for(int i=0;i<n;++i)
        if( on[i] == 0)
            cont++;
    cout<<cont<<endl;
    return 0;
}
