#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define mod 10000007
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    long long int pow2[lim];
    struct node
    {
        long long int cont;
        long long int misi;
        node *left,*right;
        node(long long int cont,int misi,node *left,node *right):
            cont(cont),misi(misi),left(left),right(right){}

        node* add(int l,int r,int w);
    };
    node *null = new node(0,0,NULL,NULL);
    node* node::add(int l,int r,int w)
    {
        if( l<=w && w<r)
        {
            if(l+1 == r)
            {
                return new node((this->cont+ 1LL*pow2[w])%mod,this->misi+1,null,null);
            }
            int m = (l+r)>>1;
            return new node((this->cont+ 1LL*pow2[w])%mod,this->misi+1,this->left->add(l,m,w),this->right->add(m,r,w));
        }
        return this;
    }
    int ans1 ,match1,match2;
    void query(node *a,node *b,node *c,node *d, int l,int r)
    {


        if( l+1 == r)
        {
          //  printf("lll = %d\n",l);
            if( match1 == match2)
             {
                 int temp1 = b->misi - a->misi;
                 int temp2 = d->misi - c->misi;
                 ans1 = ans1 + abs(temp1-temp2);
                 match1 +=temp1;
                 match2 +=temp2;
          //      printf("=== %d\n",ans1);
             }
             else if( match1 > match2 )
             {
                 int temp1 = b->misi - a->misi;
                 int temp2 = d->misi - c->misi;
                 if( match2+temp2 >= match1)
                 {
                     ans1 = ans1 + match1 - match2;
                     temp2 = temp2 - match1 + match2;
                     ans1 = ans1 + abs(temp1-temp2);
                     match1 = match2;
                     match1 +=temp1;
                     match2 +=temp2;

                 }
                 else
                 {
                    ans1 = temp1 + ans1 + temp2;
                    match1+=temp1;
                    match2+=temp2;
                 }
         //       printf(">>> %d\n",ans1);
             }
             else if(match2 > match1)
             {
                 int temp1 = b->misi - a->misi;
                 int temp2 = d->misi - c->misi;
                 if( match1 + temp1 >= match2)
                 {
                     ans1 = ans1 + match2 - match1;
                     temp1 = temp1 - match2 + match1;
                     ans1 = ans1 + abs(temp1-temp2);
                     match1 = match2;
                     match1+=temp1;
                     match2+=temp2;
                 }
                 else
                 {
                     ans1 = ans1 + temp1 + temp2;
                     match1+=temp1;
                     match2+=temp2;
                 }
        //        printf("<<< %d\n",ans1);
             }
       //     printf("ans = %d\n",ans1);
            return ;
        }
        int m = (l+r)>>1;
        long long int  cont1 = b->left->cont - a->left->cont;
        long long int  cont2 = d->left->cont - c->left->cont;
      //  printf("%lld %lld %d %d\n",cont1,cont2,l,r);
        if( cont1 < 0)
            cont1+=mod;
        if( cont2 < 0)
            cont2+=mod;

        if( cont1 != cont2 || match1 != match2 )
        {

            query(a->left,b->left,c->left,d->left,l,m);
        }
        cont1 = b->right->cont - a->right->cont;
        cont2 = d->right->cont - c->right->cont;
       // printf("%lld %lld %d %d\n",cont1,cont2,l,r);
        if( cont1 < 0)
            cont1+=mod;
        if( cont2 < 0)
            cont2+=mod;
        if( cont1 != cont2 || match1 != match2)
        {
            query(a->right,b->right,c->right,d->right,m,r);
        }
    }

    long long int a[lim],rm[lim];
    node *root[6][lim];

    int main()
    {
        int t;
        scanf("%d",&t);
        pow2[0] = 1;
        for(int i=1;i<lim;++i)
            pow2[i] = (1LL*pow2[i-1]*2)%mod;
        for(int x=0;x<t;++x)
        {


            int n,m;
            scanf("%d %d",&n,&m);
            map<int,int> M;
            M.clear();
            for(int i=0;i<n;++i)
            {
                scanf("%lld",&a[i]);
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
                root[x][i] = (i==0?null:root[x][i-1])->add(1,100001,a[i]);
            }
            while(m--)
            {
                int u,v,l,r;
                scanf("%d %d %d %d",&u,&v,&l,&r);
                u--;
                v--;
                l--;
                r--;
                ans1 = 0;
                match1 = 0;
                match2 = 0;
                query((u==0?null:root[x][u-1]),root[x][v],(l==0?null:root[x][l-1]),root[x][r],0,100001);
             //   printf("%d\n",ans1);
                if(ans1 > 2)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }
        return 0;
    }
