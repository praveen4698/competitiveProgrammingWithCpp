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
const ll MOD = 1e9+7;
const ll mod = 998244353;


int main()
{
    int n;
    vector<ll> A;
    scan(n);
    map<int,ll> M;
    for(int i=0;i<n;++i){
        ll a;
        cin>>a;
        M[a] = i+1;
        A.push_back(a);
    }   
    if( n <= 3){
        cout<<"1"<<endl;
        return 0;
    }
    sort(all(A));
    set<ll> S;
    for(int i=1;i<n;++i){
        S.insert(A[i]-A[i-1]);
    }
    // cout<<S.size()<<endl;
    if( S.size() > 3){
        print(-1);
        return 0;
    }
    if( S.size() == 1){
        print(n);
        return 0;
    }
    for( ll d : S){
        for(int i=1;i<n;++i){
            if( i != n-1 && A[i]-A[i-1] != d){
                if( A[i+1]-A[i-1] == d){
                    for(int j=i+2;j<n;++j){
                        if( A[j] - A[j-1] != d){
                            print(-1);
                            return 0;
                        }
                    }
                    print(M[A[i]]);
                    return 0;
                }
                break;
            }
            if( i == n-1 && A[i]-A[i-1] != d){
                print(M[A[i]]);
                return 0;
            }
        }
        for(int i=n-2;i>=0;--i){
            if( i != 0 && A[i+1]-A[i] != d){
                break;
            }
            if( i == 0 && A[i+1]-A[i] != d){
                print(M[A[i]]);
                return 0;
            }
        }

    }
    print(-1);


    return 0;
}
