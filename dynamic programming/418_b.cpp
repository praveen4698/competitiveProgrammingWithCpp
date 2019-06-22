#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int a[1001],b[1001],ans[1001];
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        for(int i=0;i<n;++i)
            scanf("%d",&b[i]);
        map<int,int> M;
        vector<int> p;
        for(int i=0;i<n;++i)
        {
          //  printf("%d %d\n",a[i],b[i]);
            if(a[i] == b[i])
            {
                ans[i] = a[i];
                M[a[i]] =1;
            }
            else
            {
                p.push_back(i);
            }
        }
        int j=0;
        vector<int> e;
        for(int i=1;i<n+1;++i)
        {
            if(M[i] == 0)
            {

               e.push_back(i);
            }
        }
        if(e.size() == 1 )
        {
            ans[p[0]] = e[0];
        }
        else if( a[p[0]] == e[0])
        {
            if(b[p[1]] != e[0])
             {
                 ans[p[0]] = e[0];
                 ans[p[1]] = e[1];
             }
        }
        else if( a[p[0]] == e[1])
        {
            if( b[p[1]] != e[1])
            {
                ans[p[0]] = e[1];
                ans[p[1]] = e[0];
            }
        }
        else if( a[p[1]] == e[0])
        {
            if(b[p[0]] != e[0])
            {
                ans[p[1]] = e[0];
                ans[p[0]] = e[1];
            }
        }
        else if( a[p[1]] == e[1])
        {
            if(b[p[0]] != e[1])
            {
                ans[p[1]] = e[1];
                ans[p[0]] = e[0];
            }
        }
        else
        {
            ans[p[0]] = e[0];
            ans[p[1]] = e[1];
        }

        for(int i=0;i<n;++i)
            printf("%d ",ans[i]);
        return 0;
    }
