#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    struct PSTnode
    {
        PSTnode *left,*right;
        int prod;
        PSTnode(int sum):left(NULL),right(NULL),prod(sum){}; //constructor = 1;

        PSTnode(PSTnode *left,PSTnode *right):left(left),right(right),prod(1)
        {
            if(left)
                prod = (prod*1LL*left->prod)%mod;
            if(right)
                prod = (prod*1LL*right->prod)%mod;
        };

        int calc()
        {
            int res = 1;
            if(left)
                res = (res*1LL*left->prod)%mod;
            if(right)
                res = (res*1LL*right->prod)%mod;
        }
    };
    PSTnode *nodes[lim];
    PSTnode *build(int l,int r)
    {
        if(l == r)
            return new PSTnode(1);
        int mid = (l+r)/2;
        return new PSTnode(build(l,mid),build(mid+1,r));
    }
    // for range query
    int query(PSTnode *root,int l,int r,int lo,int hi)
    {
        if( lo > hi ||!root)
            return 1;
        if( l == lo && r == hi)
            return root->prod;
        int mid = (l+r)/2;
        return (query(root->left,l,mid,lo,min(mid,hi))*1LL*query(root->right,mid+1,r,max(mid+1,lo),hi))%mod;
    }
    // for kth element
    int query2(PSTnode* A,PSTnode* B,int l,int r,int k)
    {
        if(l == r)
            return l;
        int cont = A->left->prod - B->left->prod;
        int mid = (l+r)/2;
        if( cont > k)
            return query2(A->left,B->left,l,mid,k);
        else
            return query2(A->left,B->right,mid+1,r,k-cont);
    }
    PSTnode* update(PSTnode* root,int l,int r,int index,int val)
    {
        if(l == r)
            return new PSTnode(val);
        int mid = (l+r)/2;
        if(index <= mid)
            return new PSTnode(update(root->left,l,mid,index,val),root->right);
        else
            return new PSTnode(root->left,update(root->right,mid+1,r,index,val));
    }
    int main()
    {
        int n,k;

        return 0;
    }
