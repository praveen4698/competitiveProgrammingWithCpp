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
    node* node::add(int l,int r,int w)
    {
        if( l<=w && w<r)
        {
            if(l+1 == r)
            {
                return new node(this->cont+1,null,null);
            }
            int m = (l+r)>>1;
            return new node(this->cont+1,this->left->add(l,m,w),this->right->add(m,r,w));
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
        while(m--)
        {
            int u,v,k;
            scanf("%d %d %d",&u,&v,&k);
            u--;
            v--;
            int ans = query(root[v],(u==0?null:root[u-1]),0,maxi,k);
            printf("%d\n",rm[ans]);
        }
        return 0;
    }
