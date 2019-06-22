#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    struct node
    {
        int cont;
        node *left,*right;
        node(int cont,node *left,node *right):
            cont(cont),left(left),right(right){}

        node* add(int l,int r,int w);
    };
    node *null = new node(0,NULL,NULL);
    int temp = 0;
    node* node::add(int l,int r,int w)
    {
        if( l<=w && w<r)
        {
            if(l+1 == r)
            {
                if(this->cont == 0)
                    temp = 1;
                return new node((this->cont==1?1:1),null,null);
            }
            int m = (l+r)>>1;
            return new node((temp==1?this->cont+1:this->cont),this->left->add(l,m,w),this->right->add(m,r,w));
        }
        return this;
    }
    int query(node *a,node *b,int l,int r,int k)
    {
        if( l+1 == r)
            return l;
        int m = (l+r)>>1;
        int cont = a->left->cont - b->left->cont;
        if( cont >= k)
            return query(a->left,b->left,l,m,k);
        else
            return query(a->right,b->right,m,r,k-cont);
    }
    int a[lim],rm[lim];
    node *root[lim];
    int main()
    {
        int n,m;
        scanf("%d %d",&n,&m);
        map<int,int> M;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            M[a[i]];
        }
        int maxi = 0;
        map<int,int>::iterator it;
        for(it = M.begin();it!=M.end();++it)
        {
            M[it->first] = maxi;
            rm[maxi] = it->first;
            maxi++;
        }
        null->left = null->right = null;
        for(int i=0;i<n;++i)
        {
            root[i] = (i==0?null:root[i-1])->add(0,maxi,M[a[i]]);
        }
        int prev = 0;
        while(m--)
        {
            int a,b,c,d,k;
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
            int u,v;
            u = (a*max(prev,0) + b)%n ;
            v = (c*max(prev,0) + d)%n ;
            int ans = -1;

            printf("asas = %d %d\n",u,v);
            if( u > v)
                swap(u,v);
            if( (root[v]->cont - (u==0?null:root[u-1])->cont) >= k)
             {
                 temp = 0;
                 ans = query(root[v],(u==0?null:root[u-1]),0,maxi,k);
                 printf("%d\n",rm[ans]);
                 prev = rm[ans];
             }
             else
             {
                 printf("-1\n");
                 prev = -1;
             }


        }
        return 0;
    }

