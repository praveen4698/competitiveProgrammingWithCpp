#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 101;
int small[lim],large[lim];
int main()
{
    memset(small,INF,sizeof(small));
    memset(large,-1,sizeof(large));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int a;
            cin>>a;
            small[i] = min(small[i],a);
            large[j] = max(large[j],a);
        }
    }
    int flag = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            //cout<<small[i]<<" "<<large[j]<<endl;
            if( small[i] == large[j])
            {
                cout<<small[i]<<endl;
                flag = 1;
            }
            if( flag == 1)
                break;
        }
        if( flag == 1)
            break;
    }
    if( flag == 0)
        cout<<"GUESS"<<endl;
    return 0;
}
