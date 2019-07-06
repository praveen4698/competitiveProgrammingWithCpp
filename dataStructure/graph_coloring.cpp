#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int height(int a)
    {
        int hi = 0;
        while(a >0)
        {
            a = a/2;
            hi++;
        }
        return hi;

    }
    int lca(int a,int b)
    {
        while(a!=b)
        {
            if( a>b)
                a/=2;
            else
                b/=2;
        }
        return a;
    }
    int main()
    {
        int root = 0;
        int t;
        scanf("%d",&t);
        while(t--)
        {
            string s;
            cin>>s;
            if(s[1] == 'i')
            {
                root = 1-root;
            }
            else if( s[1] == 'r')
            {
                int a,b;
                cin>>a>>b;
                int c = lca(a,b);
                int ha = height(a);
                int hb = height(b);
                int hc = height(c);
                int ra = ha/2;
                int rb = hb/2;
                int rc = hc/2;
                if(root == 1)
                {
                    if( ha%2 ==1)
                        ra++;
                    if( hb%2 == 1)
                        rb++;
                    if( hc%2 == 1)
                        rc++;
                }
                int flag = 0;
                if( root == 0)
                {
                    if( hc%2 == 0)
                        flag = 1;
                }
                if( root == 1)
                {
                    if(hc%2 == 1)
                        flag =1 ;
                }
                int ans = ra + rb - 2*rc +flag;
                printf("%d\n",ans);
            }
            else
            {
                int a,b;
                cin>>a>>b;
                int c = lca(a,b);
                int ha = height(a);
                int hb = height(b);
                int hc = height(c);
                int ra = ha/2;
                int rb = hb/2;
                int rc = hc/2;
                if(root == 0)
                {
                    if(ha%2 == 1)
                        ra++;
                    if(hb%2 == 1)
                        rb++;
                    if(hc%2 == 1)
                        rc++;
                }
                int flag = 0;
                if( root == 0)
                {
                    if( hc%2 == 1)
                        flag =1;
                }
                if( root == 1)
                {
                    if( hc%2 == 0)
                        flag = 1;
                }
                int ans = ra+rb-2*rc + flag ;
                printf("%d\n",ans);
            }
        }
        return 0;
    }
