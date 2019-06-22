#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define scan(a) scanf("%d",&a)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int A[10001];
        bool visited[10001];
        int n,m;
        scan(n);
        scan(m);
        queue<int> Q;
        memset(A,INF,sizeof(A));
        memset(visited,false,sizeof(visited));
        A[n] = 0;
        Q.push(n);
        while(!Q.empty())
        {
            int i = Q.front();
            visited[i] = true;
            Q.pop();
            if( 2*i <= 10000 && visited[2*i] == false && A[2*i] > A[i]+1)
                A[2*i] = A[i] + 1,Q.push(2*i);
            if( i-1 >= 0 && visited[i-1] == false && A[i-1] > A[i] + 1)
                A[i-1] = A[i] + 1,Q.push(i-1);


        }
        printf("%d",A[m]);
        return 0;
    }

