#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    struct PSTnode
    {
        PSTnode *left,*right;
        int value;
        PSTnode(int val):left(NULL),right(NULL),value(val){}; //constructor = 1;

        PSTnode(PSTnode *left,PSTnode *right):left(left),right(right)
        {
            value = 0;
            if(left)
                value = left->value;
            if(right)
                value += right->value;
        };

      /*  int calc()
        {
            int res = 1;
            if(left)
                res = (res*1LL*left->prod)%mod;
            if(right)
                res = (res*1LL*right->prod)%mod;
        } */
    };
    PSTnode *nodes[lim];
    PSTnode *build(int l,int r)
    {
       // printf("%d %d\n",l,r);
        if(l == r)
            return new PSTnode(0);
        int mid = (l+r)/2;
        return new PSTnode(build(l,mid),build(mid+1,r));
    }
    int query2(PSTnode* A,PSTnode* B,int l,int r,int k)
    {
        if(l == r)
            return l;
        int cont = A->left->value - B->left->value;
        int mid = (l+r)/2;
       // printf("%d %d %d %d\n",l,r,cont,k);
        if( cont >= k)
            return query2(A->left,B->left,l,mid,k);
        else
            return query2(A->left,B->right,mid+1,r,k-cont);
    }
    PSTnode* update(PSTnode* root,int l,int r,int index)
    {

        if(l == r)
            return new PSTnode(1);
        int mid = (l+r)/2;
        //printf("%d %d %d %d\n",l,r,mid,index);
       // if(root->left!=NULL)
        //    printf("yo");

        if(index <= mid)
            return new PSTnode(update(root->left,l,mid,index),root->right);
        else
            return new PSTnode(root->left,update(root->right,mid+1,r,index));
    }
    void print(PSTnode* A,int l,int r)
    {
        if( A == NULL)
            return;
        printf("%d %d %d\n",A->value,l,r);
        int mid = (l+r)/2;
        print(A->left,l,mid);
        print(A->right,mid+1,r);
    }
    int main()
    {
        int n,q;
        scanf("%d %d",&n,&q);
        vector<int> A;
        set<int> B;
        map<int,int> M,M2;
        for(int i=0;i<n;++i)
        {
            int a;
            scanf("%d",&a);
            A.push_back(a);
            B.insert(a);
        }
        int m = B.size();
        int cont = 0;
        for(auto s:B)
        {
            M[s]  =  cont;
            M2[cont] = s;
            cont++;
        }
       // cout<<"yo";
        nodes[0] = build(0,m);
        for(int i=0;i<n;++i)
        {
            //printf("yo");
           // printf("%d =======",i);
            nodes[i+1] = update(nodes[i],0,m,M[A[i]]);
           // printf("yo");
        }
        for(int i=0;i<n+1;++i)
        {
            printf("%d =====\n",i);
            print(nodes[i],0,m);
        }
        int prev = 0;
        while(q--)
        {
            int a,b,c,d,k;
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
            int u,v;
            u = ((a*max(prev,0) + b)%n)  +1 ;
            v = ((c*max(prev,0) + d)%n)   +1;
           // int ans = -1;

            printf("asas = %d %d\n",u,v);
            if( u > v)
                swap(u,v);
          //  printf("val = %d\n",nodes[v]->value - nodes[u-1]->value);
            if( nodes[v]->value - nodes[u-1]->value >= k)
            {
                int ans = query2(nodes[v],nodes[u-1],0,m,k);
                printf("%d\n",M2[ans]);
                prev = M2[ans];
            }
            else
            {
                printf("-1\n");
                prev = -1;
            }

        }

        return 0;
    }
