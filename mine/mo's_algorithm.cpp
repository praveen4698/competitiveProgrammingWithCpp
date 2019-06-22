#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

const int block = 250;
const int lim = 1e6+10;
int nodes[8*lim],active_left[lim],active_right[lim];
int A[lim];
vector<int> cont[lim];
int s[lim];
int ans[lim];
struct node
{
    int i,l,r;
} q[lim];

inline bool comp(node x,node y)
{
    if( x.l/block != y.l/block)
        return x.l/block < y.l/block;
    return x.r < y.r;
}

inline void update(int st,int l,int r,int idx,int value)
{
    if( l == r)
    {
        nodes[st] = value;
        return ;
    }
    int mid = (l+r)/2;
    if( idx > mid)
        update(2*st+1,mid+1,r,idx,value);
    else
        update(2*st,l,mid,idx,value);
    nodes[st] = max(nodes[2*st],nodes[2*st + 1]);
}

inline void add(int val,int f)
{
        int &l = active_left[val];
        int &r = active_right[val];
        if(f)
        {
            r++;
            if( l == -1)
                l++;
        }
        else
            l--;
      //  printf("asdp %d %d %d %d %d \n",val,active_left[val],active_right[val],cont[val][active_right[val]],cont[val][active_left[val]]);
        update(1,0,1000001,val,cont[val][r]-cont[val][l]);
    }

inline void remov(int val,int f)
{
    int &l = active_left[val];
    int &r = active_right[val];
    if( l > r)
        return ;
    if(!f)
        l++;
    else
        r--;
    if( l > r)
        return ;
       // printf("asdp %d %d %d %d %d \n",val,active_left[val],active_right[val],cont[val][active_right[val]],cont[val][active_left[val]]);
    update(1,0,1000001,val,cont[val][r]-cont[val][l]);
}

    int main()
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        s[0] = 0;
        cont[0].push_back(0);
        for(int i=1;i<=n;++i)
        {
            s[i] = (A[i-1] + s[i-1])%k;
            cont[s[i]].push_back(i);
        }
      /*  for(int i=0;i<k;++i)
        {
            printf("%d ===  ",i);
            for(auto j:cont[i])
                printf("%d ",j);
            printf("\n");
        } */
        for(int i=0;i<lim;++i)
            active_left[i] = active_right[i] = -1;

        for(int i=0;i<m;++i)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            q[i].l = a-1;
            q[i].r = b;
            q[i].i = i;
        }
        sort(q,q+m,comp);
        int currentL = 0;
        int currentR = 0;
        for(int i=0;i<m;++i)
        {
            int l = q[i].l;
            int r = q[i].r;
            while(currentR <= r)
            {
                add(s[currentR],1);
                currentR++;
            }
            while(currentR > r+1)
            {
                remov(s[currentR-1],1);
                currentR--;
            }
            while(currentL > l)
            {
                add(s[currentL-1],0);
                currentL--;
            }
            while(currentL < l)
            {
                remov(s[currentL],0);
                currentL++;
            }
            ans[q[i].i] = nodes[1];
        }
        for(int i=0;i<m;++i)
            printf("%d\n",ans[i]);
    }
