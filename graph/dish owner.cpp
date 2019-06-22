#include<bits/stdc++.h>
using namespace std;
#define loop(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int maxi[10001];
    int S[10001];
    int parent[10001];

    int parents(int k)
    {
        if( parent[k] == k)
            return k;
        parent[k] = parents(parent[k]);
        return parent[k];
    }

    int main()
    {
        int Z;
        scanf("%d",&Z);
        while(Z--)
        {
            int n;
            scanf("%d",&n);
            loop(i,1,n+1)
            {
                scanf("%d",&maxi[i]);
                parent[i] = i;

            }
            int Q;
            scanf("%d",&Q);

            while(Q--)
            {
                int a;
                scanf("%d",&a);
                if( a == 0)
                {
                    int x,y;
                    scanf("%d %d",&x,&y);
                    int px = parents(x);
                    int py = parents(y);
                    if( px == py)
                    {
                        printf("Invalid query!\n");
                        continue;
                    }
                    if( maxi[px] > maxi[py])
                    {
                        parent[py] = px;
                    }
                    if( maxi[py] > maxi[px])
                    {
                        parent[px] = py;
                    }

                }
                else
                {
                    int x;
                    scanf("%d",&x);
                    printf("%d\n",parents(x));
                }
            }

        }
        return 0;
    }
