#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 3001;
unordered_map<int,int> L[lim],R[lim];
inline int readint()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f = -1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
vector<int> B[200001];
int main()
{
    int A[lim];
    int n,q;
    //scanf("%d %d",&n,&q);
    n = readint();
    q = readint();
    for(int i=0;i<n;++i)
    {
        A[i] = readint();
        B[A[i]].push_back(i);
    }
    for(int i=0;i<n;++i)
    {
      /*  for(int j=0;j<n;++j)
        {
            if( L[i].find(A[(i+j)%n])  == L[i].end())
                L[i][A[(i+j)%n]] = j;
            else
                L[i][A[(i+j)%n]] = min(j,L[i][A[(i+j)%n]]);
            if( R[i].find(A[(i-j+n)%n]) == R[i].end())
                R[i][A[(i-j+n)%n]] = j;
            else
                R[i][A[(i-j+n)%n]] = min(j,R[i][A[(i-j+n)%n]]);
        } */
    }
    while(q--)
    {
        int a,b;
        char c;
        a = readint();
        b = readint();
        scanf("%c",&c);
        if( c == 'R')
        {
            if( B[b].size() == 0)
                printf("-1\n");
            else
            {
                int ans = INF;
                for(auto i:B[b])
                {
                    if( i < a)
                        ans = min(ans,n-(a-i));
                    else
                        ans = min(ans,i-a);
                }
                printf("%d\n",ans);
            }
        }
        else
        {
            if( B[b].size() == 0)
                printf("-1\n");
            else
            {
                int ans = INF;
                for(auto i:B[b])
                {
                    if( i > a)
                        ans = min(ans,n-(i-a));
                    else
                        ans = min(ans,a-i);
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
