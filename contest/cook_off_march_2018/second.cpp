#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 101;
int row[lim][lim],A[lim][lim],col[lim][lim];
int main()
{
    int t;
    scan(t);
    while(t--)
    {
        int n,m;
        scan2(n,m);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>A[i][j];
                row[i][j] = 1;
                col[i][j] = 1;
            }
        }
        int flag  = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if( A[i][j] == -1)
                {
                    A[i][j] = max(row[i][j],col[i][j]);
                   // cout<<A[i][j]<<endl;
                    row[i][j+1] = max(row[i][j],A[i][j]);
                    col[i+1][j] = max(col[i][j],A[i][j]);
                }
                else
                {
                   // cout<<A[i][j]<<" "<<row[i][j]<<" "<<col[i][j]<<endl;
                    if(A[i][j] < row[i][j] || A[i][j] < col[i][j])
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {

                        row[i][j+1] = max(row[i][j],A[i][j]);
                        col[i+1][j] = max(col[i][j],A[i][j]);
                    }

                }
            }
            if( flag == 1)
                break;
        }
        if( flag == 1)
            cout<<"-1"<<endl;
        else
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<m;++j)
                {
                    printf("%d ",A[i][j]);
                }
                cout<<endl;
            }
        }
    }
    return 0;
}


