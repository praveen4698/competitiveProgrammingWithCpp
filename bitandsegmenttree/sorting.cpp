#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 5e5+10;
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
    int y = 0;
    long long int query2(int l,int r,int n)
    {


        if( l >=r)
            return 0;
        int ans = query(root[r],(l==1?null:root[l-1]),0,n,(r-l+2)/2);

        int pivot = rm[ans];
        return 1LL*(r-l+1)+ 1LL*query2(l,pivot-1,n)+ 1LL*query2(pivot+1,r,n);
    }
    int main()
    {
        int n,m;
        scanf("%d",&n);
        map<int,int> M;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            M[a[i]] = i;
            rm[i] = a[i];
        }
        int maxi = n+1;
        null->left = null->right = null;
        for(int i=1;i<n+1;++i)
        {
            root[i] = (i==1?null:root[i-1])->add(0,maxi,M[i]);
        }
        long long int ans = query2(1,n,maxi);
        printf("%lld\n",ans);
        return 0;
    }
