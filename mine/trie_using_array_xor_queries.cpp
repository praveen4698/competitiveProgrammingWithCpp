#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e7;
    int ans,n,v;
    int a[lim][2],sz[lim],ind[lim],root[lim],ww[20];
    void add(int pr,int nr,int x)
    {
        for(int i=18;i>=0;i--)
        {
            int e = (x&(1<<i));
            if(e != 0)
                e = 1;
            v++;
            ww[i] = nr;
            ind[v] = n;
            a[nr][e] = v;
            a[nr][1-e] = a[pr][1-e];
            sz[nr] = sz[a[nr][1-e]];
            nr = v;
            pr= a[pr][e];
        }
        sz[nr]+=sz[pr]+1;
        for(int i=0;i<=18;++i)
            sz[ww[i]] = sz[a[ww[i]][0]] + sz[a[ww[i]][1]];
    }
    void findxor(int v,int l,int x)
    {
        for(int i=18;i>=0;i--)
        {
            int e = (x&(1<<i));
            if( e!= 0)
                e = 1;
            if( ind[a[v][1-e]] >= l)
            {
                v = a[v][1-e];
                ans+=(1-e)*(1<<i);
            }
            else
            {
                v = a[v][e];
                ans+=e*(1<<i);
            }
        }
    }
    int findless(int v,int x)
    {
        int ans = 0;
        for(int i=18;i>=0;i--)
        {
            int e = (x&(1<<i));
            if( e!=0)
                e = 1;
            for(int j=0;j<e;j++)
                ans+=sz[a[v][j]];

            v = a[v][e];
        }
        ans+=sz[v];
        return ans;
    }
    void findkth(int vr,int vl,int x)
    {
        for(int i=18;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                int temp = sz[a[vr][j]] - sz[a[vl][j]];
                if( temp < x)
                    x-=temp;
                else
                {
                    vr= a[vr][j];
                    vl=a[vl][j];
                    ans+=j*(1<<i);
                    break;
                }

            }
        }
    }
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int ty ;
            scanf("%d",&ty);
            if( ty == 0)
            {
                int x;
                scanf("%d",&x);
                n++;
                v++;
                root[n]=v;
                ind[v] = n;
                add(root[n-1],root[n],x);
            }
            else if( ty == 1)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                ans = 0;
                findxor(root[b],a,c);
                printf("%d\n",ans);
            }
            else if( ty == 2)
            {
                int x;
                scanf("%d",&x);
                n = n-x;
            }
            else if( ty == 3)
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                ans = 0;
                ans = findless(root[b],c) - findless(root[a-1],c);
                printf("%d\n",ans);

            }
            else
            {
                int a,b,c;
                scanf("%d %d %d",&a,&b,&c);
                ans = 0;
                findkth(root[b],root[a-1],c);
                printf("%d\n",ans);
            }
        }

        return 0;
    }
