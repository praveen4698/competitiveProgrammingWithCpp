#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

map<int,int> M;
vector<int> A;
vector<int> P,ans;
int main()
{

    int t;
    scan(t);
    while(t--){
        int n,m;
        scan2(n,m);
        A.clear();
        M.clear();
        ans.clear();
        for(int i=0;i<n;++i){
            int a,b;
            scan2(a,b);
            M[a] = b;
            A.push_back(a);
        }
        sort(all(A));
        for(int i=0;i<m;++i){
            int p;
            scan(p);
            auto itr = upper_bound(all(A),p);
            if(itr == A.end()){
                if( M[A[n-1]] > p){
                    ans.push_back(0);
                }
                else
                    ans.push_back(-1);
            }
            else{
                int tt = itr - A.begin();
                if( tt == 0){
                    ans.push_back(A[tt]-p);
                }
                else if( A[tt-1] == p){

                    ans.push_back(0);
                }
                else if( M[A[tt-1]] > p){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(A[tt]-p);
                }

            }
        }
        for(auto a:ans)
            print(a);
    }
    return 0;
}


