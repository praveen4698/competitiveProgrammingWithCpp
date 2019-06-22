#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printfn("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {1,-1,0,1,-1,1,-1,0};
vector<string> A;
bool done[1001][1001];
int main()
{
    int n,m;
    scan2(n,m);
    A.resize(n);
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    memset(done,true,sizeof(done));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if( i==0||j==0||i==n-1||j==m-1)
                done[i][j] = false;
            if( A[i][j] == '.'){
                for(int k=0;k<8;++k){
                    if( i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m)
                        done[i+dx[k]][j+dy[k]] = false;
                }
            }

        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if( A[i][j] == '#'){
                    int cont = 0;
                for(int k=0;k<8;++k){
                    if( i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m && done[i+dx[k]][j+dy[k]] == true)
                        cont++;
                }
                if( cont == 0){
                    cout<<"No"<<endl;
                    return 0;
                }
        }
    }}




    cout<<"Yes"<<endl;
    return 0;
}


