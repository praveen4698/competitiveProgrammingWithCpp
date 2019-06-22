#include<bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

#define root 0
const int lim = 1e5 + 10;
const int logn = 20;
int dp[lim][logn],level[lim],par[lim];// for lca
vector <int> G[lim] ;
int baseArray[lim], ptr; // for segment tree
int chainNo, chainInd[lim], chainHead[lim], posInBase[lim];
int   subsize[lim]; // for heavy light
int cost[lim];
int GCD(int a,int b){
  int r;
  if(a<0) a=-a;
  if(b<0) b=-b;
  while(a){r=b; b=a; a=r%a;}
  return b;
}
    // segmetnt tree part
    struct TNode
    {
        int l,r ;
        int st,en,diff_gcd,lazy ;
        TNode() : l(0), r(0),lazy(0) {};// constructor

        void assignLeaf(int value)
        {
            st = value;
            en = value;
            diff_gcd = 0;
            lazy = 0;
        }

        void merge(TNode& left, TNode& right)
        {
            st = left.st;
            en = right.en;
           // lazy  = 0;
            diff_gcd = GCD(left.diff_gcd,GCD(right.st-left.en,right.diff_gcd));
        }

    };

    TNode nodes[800000];
    void buildTree(int st,int left,int right)
    {
        nodes[st].l = left;
        nodes[st].r = right ;
        if(left == right)
        {
               nodes[st].assignLeaf(baseArray[left]);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(st*2,left,mid);
        buildTree(st*2+1,mid+1,right);
        nodes[st].merge(nodes[st*2],nodes[st*2+1]);
    }


        void update2(int st, int lo, int hi,int value)
        {
            if (nodes[st].l == nodes[st].r)
            {
                nodes[st].st+=value;
                nodes[st].en+=value;
                nodes[st].lazy+=value;
                return;
            }

            int mid = (nodes[st].l + nodes[st].r) / 2;
            if (lo > mid)
                update2(2*st+1,lo,hi, value);
            else if (hi <= mid)
                update2(2*st,lo,hi, value);
            else
            {
                update2(2*st ,lo, mid, value);
                update2(2*st+1,mid+1,hi, value);
            }
            nodes[st].merge(nodes[2*st], nodes[2*st+1]);
            nodes[st].st+=nodes[st].lazy;
            nodes[st].en+=nodes[st].lazy;
        }


    int query(int st,int lo,int hi,int lazysum)
    {
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            int re = GCD(nodes[st].st+lazysum,nodes[st].diff_gcd);
         //   printf("query = %d %d %d\n",nodes[st].l,nodes[st].r,re);
            return re;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        lazysum+=nodes[st].lazy;
        int  re;
        if( lo > mid)
            re = query(2*st+1,lo,hi,lazysum);
        else if( hi <= mid)
            re = query(2*st,lo,hi,lazysum);
        else
        {
            int lr = query(2*st, lo, mid,lazysum);
            int rr = query(2*st+1, mid+1, hi,lazysum);
            re = GCD(lr,rr);
        }

		return re;

    }


    int query_up(int u, int v)
    {
       // if(u == v) return 0; // Trivial
        int uchain, vchain = chainInd[v], ans = 0;
        while(1)
        {
            uchain = chainInd[u];
            if(uchain == vchain)
            {
                //if(u==v) break;
                int result = query(1, posInBase[v], posInBase[u],0);
                ans = GCD(ans,result);
                break;
            }
            int result = query(1,posInBase[chainHead[uchain]], posInBase[u],0 );
            ans = GCD(ans,result);
            u = chainHead[uchain];
            u = dp[u][0];
        }
        return ans;
    }
    void update_up(int u, int v,int value)
    {
       // if(u == v) return 0; // Trivial
        int uchain, vchain = chainInd[v], ans = 0;
        while(1)
        {
            uchain = chainInd[u];
            if(uchain == vchain)
            {
                //if(u==v) break;
                update2(1, posInBase[v], posInBase[u],value);
                break;
            }
            update2(1,posInBase[chainHead[uchain]], posInBase[u],value);
            u = chainHead[uchain];
            u = dp[u][0];
        }

    }
    // lca part
    void DFS0(int u)
    {
      //  cout<<u<<endl;
        for(auto it:G[u])
        {
            if(dp[u][0] != it)
            {
                dp[it][0] = u;
                level[it] = level[u] + 1;
                DFS0(it);
            }
        }
    }
    void preprocess(int n)
    {
        dp[0][0] = 0;
        level[0] = 0;
        DFS0(0);
        for(int j=1;j<logn;++j)
        {
            for(int i=0;i<n;++i)
            {
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
    int lca(int a,int b)
    {
        if(level[b] < level[a])
            swap(a,b);
        int d = level[b] - level[a];
        for(int i=0;i<logn;++i)
        {
            if(d&(1<<i))
                b = dp[b][i];
        }
        if( a== b)
            return b;

        for(int i=logn-1;i>=0;i--)
        {
            if(dp[a][i] != dp[b][i])
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        return dp[a][0];
    }
    void query1(int u, int v)
    {

        int lca1 = lca(u, v);
        int ans = query_up(u, lca1);
        int temp = query_up(v, lca1);
        ans = GCD(ans,temp);
        printf("%d\n", ans);
    }


    void change(int u,int v,int value)
    {
        int lca1 = lca(u,v);
        update_up(u,lca1,value);
        update_up(v,lca1,value);
        update_up(lca1,lca1,-1*value);

    }

    // heavy light deconmpostion
    // start
    void HLD(int curNode, int prev)
    {
        if(chainHead[chainNo] == -1)
        {
            chainHead[chainNo] = curNode;
        }
        chainInd[curNode] = chainNo;
        posInBase[curNode] = ptr;
        baseArray[ptr++] = cost[curNode];

        int sc = -1, ncost;

        for(int g:G[curNode])
        {

            if(g != prev)
            {
                if(sc == -1 || subsize[sc] < subsize[g])
                {
                    sc = g;
                }
            }
        }

        if(sc != -1)
            HLD(sc, curNode);

        for(int g:G[curNode])
            if(g != prev)
            {
                if(sc != g)
                {
                    chainNo++;
                    HLD(g, curNode);
                }
            }
        return ;
    }
    // end

    void DFS1(int cur, int prev)
    {
        subsize[cur] = 1;
        for(int g:G[cur])
            if(g!= prev)
            {
                DFS1(g, cur);
                subsize[cur] += subsize[g];
            }
    }

    int main() {
        int t;
        t=1;
        while(t--)
        {
            ptr = 0;
            int n;
            scanf("%d", &n);

            for(int i=0; i<n; i++)
            {
                G[i].clear();

                chainHead[i] = -1;

            }
            for(int i=1;i<n;i++)
            {
                int u, v;
                scanf("%d %d", &u, &v);
                //u--; v--;
                G[u].push_back(v);
                G[v].push_back(u);

            }
            for(int i=0;i<n;++i)
                scanf("%d",&cost[i]);
            chainNo = 0;
            DFS1(root, -1);
           // cout<<"dfs1"<<endl;
            HLD(root, -1);
           // cout<<"hld"<<endl;
            buildTree(1, 0, n-1);
            //cout<<"build"<<endl;
            preprocess(n);
           // cout<<"la"<<endl;
            int q;
            cin>>q;
          //  for(int i=0;i<n;++i)
          //      printf("%d %d\n",chainInd[i],posInBase[i]);
            cout<<endl;
            while(q--)
            {
                char a;
                int b,c,d;
                cin>>a;
                if( a == 'F')
                {
                    cin>>b>>c;
                    query1(b,c);
                }
                else
                {
                    cin>>b>>c>>d;
                    change(b,c,d);
                }

            }
        }
        return 0;
    }
