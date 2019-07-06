#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

#define root 0
#define N 10100
#define LN 14

vector <int> adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];


    struct SegmentTreeNode
    {
        int left,right ;
        int sum ;
        SegmentTreeNode() : left(0), right(0) {};// constructor

        void assignLeaf(int value)
        {
            sum = value;
        }

        void merge(SegmentTreeNode& left, SegmentTreeNode& right)
        {
            if( left.sum > right.sum)
                sum = left.sum;
            else
                sum = right.sum;
        }

    };

    SegmentTreeNode nodes[800000];
    void buildTree(int stindex,int left,int right)
    {
        nodes[stindex].left = left;
        nodes[stindex].right = right ;
        if(left == right)
        {
               nodes[stindex].assignLeaf(baseArray[left]);
               return ;
        }
        int mid = (left + right)/2;
        buildTree(stindex*2,left,mid);
        buildTree(stindex*2+1,mid+1,right);
        nodes[stindex].merge(nodes[stindex*2],nodes[stindex*2+1]);
    }


    void update(int stindex ,int index, int value)
    {

		if (nodes[stindex].left == nodes[stindex].right)
        {
			nodes[stindex].assignLeaf(value);
			return;
		}

		int  mid = (nodes[stindex].left + nodes[stindex].right) / 2;
		if (index <= mid)
			update(stindex*2, index, value);
		else
			update(stindex*2+1, index, value);

		nodes[stindex].merge(nodes[2*stindex], nodes[2*stindex+1]);
	}

    SegmentTreeNode query(int stindex,int lo,int hi)
    {
        if(nodes[stindex].left == lo && nodes[stindex].right == hi)
        {
            SegmentTreeNode result = nodes[stindex];
            return result;
        }
        int mid = (nodes[stindex].left + nodes[stindex].right)/2;
        SegmentTreeNode result;
        if( lo > mid)
            result = query(2*stindex+1,lo,hi);
        else if( hi <= mid)
            result = query(2*stindex,lo,hi);
        else
        {
            SegmentTreeNode leftResult = query(2*stindex, lo, mid);
            SegmentTreeNode rightResult = query(2*stindex+1, mid+1, hi);
            result.left = leftResult.left;
            result.right = rightResult.right;
            result.merge(leftResult, rightResult);
        }

		return result;

    }


    int query_up(int u, int v)
    {
        if(u == v) return 0;
        int uchain, vchain = chainInd[v], ans = -1;

        while(1)
        {
            uchain = chainInd[u];
            if(uchain == vchain)
            {

                if(u==v) break;
                SegmentTreeNode result = query(1, posInBase[v]+1, posInBase[u]);

                if(result.sum > ans) ans = result.sum;
                break;
            }
            SegmentTreeNode result = query(1,posInBase[chainHead[uchain]], posInBase[u] );

            if(result.sum > ans)
                ans = result.sum;
            u = chainHead[uchain];
            u = pa[0][u];
        }
        return ans;
    }


    int LCA(int u, int v)
    {
        if(depth[u] < depth[v])
            swap(u,v);
        int diff = depth[u] - depth[v];
        for(int i=0; i<LN; i++)
            if( (diff>>i)&1 )
                u = pa[i][u];
        if(u == v)
            return u;
        for(int i=LN-1; i>=0; i--)
            if(pa[i][u] != pa[i][v])
            {
                u = pa[i][u];
                v = pa[i][v];
            }
        return pa[0][u];
    }

    void query(int u, int v)
     {

        int lca = LCA(u, v);
        int ans = query_up(u, lca);
        int temp = query_up(v, lca);
        if(temp > ans) ans = temp;
        printf("%d\n", ans);
    }


    void change(int i, int val)
    {
        int u = otherEnd[i];
        update(1, posInBase[u], val);
    }


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
            if(adj[curNode][i] != prev)
            {
                if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]])
                 {
                    sc = adj[curNode][i];
                    ncost = costs[curNode][i];
                  }
            }

        if(sc != -1)
        {

            HLD(sc, ncost, curNode);
        }

        for(int i=0; i<adj[curNode].size(); i++)
            if(adj[curNode][i] != prev)
            {
                if(sc != adj[curNode][i])
                 {

                    chainNo++;
                    HLD(adj[curNode][i], costs[curNode][i], curNode);
                }
            }
    }


    void dfs(int cur, int prev, int _depth=0)
    {
        pa[0][cur] = prev;
        depth[cur] = _depth;
        subsize[cur] = 1;
        for(int i=0; i<adj[cur].size(); i++)
            if(adj[cur][i] != prev)
            {
                otherEnd[indexx[cur][i]] = adj[cur][i];
                dfs(adj[cur][i], cur, _depth+1);
                subsize[cur] += subsize[adj[cur][i]];
            }
    }

    int main()
     {
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
                for(int j=0; j<LN; j++)
                    pa[j][i] = -1;
            }
            for(int i=1; i<n; i++)
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
            dfs(root, -1);
            HLD(root, -1, -1);
            buildTree(1, 0, ptr-1);


            for(int i=1; i<LN; i++)
                for(int j=0; j<n; j++)
                    if(pa[i-1][j] != -1)
                        pa[i][j] = pa[i-1][pa[i-1][j]];

            while(1)
            {
                char s[100];
                scanf("%s", s);
                if(s[0]=='D')
                {
                    break;
                }
                int a, b;
                scanf("%d %d", &a, &b);
                if(s[0]=='Q')
                {
                    query(a-1, b-1);
                }
                else
                {
                    change(a-1, b);
                }
            }
        }
    }
