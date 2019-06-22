#include<bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

#define root 0
const int lim = 1e5 + 10;
const int logn = 20;
int dp[lim][logn],level[lim],par[lim];
vector <int> adj[lim], costs[lim], indexx[lim];
int baseArray[lim], ptr;
int chainNo, chainInd[lim], chainHead[lim], posInBase[lim];
int  otherEnd[lim], subsize[lim];

    // segmetnt tree part
    struct TNode
    {
        int l,r ;
        int sum ;
        TNode() : l(0), r(0) {};// constructor

        void assignLeaf(int value)
        {
            sum = value;
        }

        void merge(TNode& left, TNode& right)
        {
            if( left.sum > right.sum)
                sum = left.sum;
            else
                sum = right.sum;
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


    void update(int st ,int index, int value)
    {

		if (nodes[st].l == nodes[st].r)
        {
			nodes[st].assignLeaf(value);
			return;
		}

		int  mid = (nodes[st].l + nodes[st].r) / 2;
		if (index <= mid)
			update(st*2, index, value);
		else
			update(st*2+1, index, value);

		nodes[st].merge(nodes[2*st], nodes[2*st+1]);
	}


    TNode query(int st,int lo,int hi)
    {
        if(nodes[st].l == lo && nodes[st].r == hi)
        {
            TNode re = nodes[st];
            return re;
        }
        int mid = (nodes[st].l + nodes[st].r)/2;
        TNode re;
        if( lo > mid)
            re = query(2*st+1,lo,hi);
        else if( hi <= mid)
            re = query(2*st,lo,hi);
        else
        {
            TNode lr = query(2*st, lo, mid);
            TNode rr = query(2*st+1, mid+1, hi);
            re.l = lr.l;
            re.r = rr.r;
            re.merge(lr,rr);
        }

		return re;

    }


    int query_up(int u, int v)
    {
        if(u == v) return 0; // Trivial
        int uchain, vchain = chainInd[v], ans = -1;
        while(1)
        {
            uchain = chainInd[u];
            if(uchain == vchain)
            {
                if(u==v) break;
                TNode result = query(1, posInBase[v]+1, posInBase[u]);
                if(result.sum > ans) ans = result.sum;
                    break;
            }
            TNode result = query(1,posInBase[chainHead[uchain]], posInBase[u] );
            if(result.sum > ans)
                ans = result.sum;
            u = chainHead[uchain];
            u = dp[u][0];
        }
        return ans;
    }
    // lca part
    void DFS0(int u)
    {
        for(auto it:adj[u])
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
    void query(int u, int v)
    {

        int lca1 = lca(u, v);
        int ans = query_up(u, lca1);
        int temp = query_up(v, lca1);
        if(temp > ans)
            ans = temp;
        printf("%d\n", ans);
    }


    void change(int i, int val)
    {
        int u = otherEnd[i];
        update(1, posInBase[u], val);
    }

    // heavy light deconmpostion
    // start
    void HLD(int curNode, int cost, int prev)
    {
        if(chainHead[chainNo] == -1)
        {
            chainHead[chainNo] = curNode;
        }
        chainInd[curNode] = chainNo;
        posInBase[curNode] = ptr;
        baseArray[ptr++] = cost;

        int sc = -1, ncost;

        for(int i=0; i<adj[curNode].size(); i++)
        {

            if(adj[curNode][i] != prev)
            {
                if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]])
                {
                    sc = adj[curNode][i];
                    ncost = costs[curNode][i];
                }
            }
        }

        if(sc != -1)
            HLD(sc, ncost, curNode);

        for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev)
        {
            if(sc != adj[curNode][i])
            {
                chainNo++;
                HLD(adj[curNode][i], costs[curNode][i], curNode);
            }
        }
        return ;
    }
    // end

    void DFS1(int cur, int prev)
    {
        subsize[cur] = 1;
        for(int i=0; i<adj[cur].size(); i++)
            if(adj[cur][i] != prev)
            {
                otherEnd[indexx[cur][i]] = adj[cur][i]; //updation
                DFS1(adj[cur][i], cur);
                subsize[cur] += subsize[adj[cur][i]];
            }
    }

    int main() {
        int t;
        scanf("%d ", &t);
        while(t--)
        {
            ptr = 0;
            int n;
            scanf("%d", &n);

            for(int i=0; i<n; i++)
            {
                adj[i].clear();
                costs[i].clear();
                indexx[i].clear();
                chainHead[i] = -1;

            }
            for(int i=1;i<n;i++)
            {
                int u, v, c;
                scanf("%d %d %d", &u, &v, &c);
                u--; v--;
                adj[u].push_back(v);
                costs[u].push_back(c);
                indexx[u].push_back(i-1);
                adj[v].push_back(u);
                costs[v].push_back(c);
                indexx[v].push_back(i-1);
            }

            chainNo = 0;
            DFS1(root, -1);
            HLD(root, -1, -1);
            buildTree(1, 0, ptr-1);
            preprocess(n);
            while(1)
            {
                char s[100];
                scanf("%s", s);
                if(s[0]=='D') {
                    break;
                }
                int a, b;
                scanf("%d %d", &a, &b);
                if(s[0]=='Q') {
                    query(a-1, b-1);
                } else {
                    change(a-1, b);
                }
            }
        }
        return 0;
    }

