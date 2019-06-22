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
deque<pair<int,int> > Q;
multiset<int> S;
vector<int> A;
int main()
{
    int n,q,k;
    string s;
    scan3(n,q,k);
    A.resize(n);
    int prev = -1;
    for(int i=0;i<n;++i){
        scan(A[i]);
        if( prev == -1){
            prev = 1;
        }
        else if( i > 0 && A[i] != A[i-1]){
            Q.push_back(make_pair(A[i-1],prev));
            // cout<<prev<<"SDFSF"<<endl;
            if( A[i-1] == 1){
                S.insert(prev);
            }
            prev = 1;
        }
        else{
            prev++;
        }
    }
    Q.push_back(make_pair(A[n-1],prev));
    if( A[n-1] == 1){
        S.insert(prev);
    }
    cin>>s;
    // cout<<"SDf"<<endl;
    // for(auto i:S)
    //     cout<<i<<endl;
    // cout<<"SDFS"<<endl;
    for(int i=0;i<q;++i){

        if( s[i] == '!'){
            if(Q.size() == 1){
                continue;
            }
            pair<int,int> f = Q.front();
            pair<int,int> l = Q.back();
            Q.pop_front();
            Q.pop_back();
            if( f.first == 1){
                S.erase(f.second);
            }
            if( l.second == 1){
                S.erase(l.second);
            }
            if( f.first == 1 && l.first == 1){
                f.second++;
                Q.push_front(f);
                l.second--;
                S.insert(f.second);
                if( l.second)
                    Q.push_back(l),S.insert(l.second);
            }
            else if( f.first == 0 && l.first == 0){
                f.second++;
                Q.push_front(f);
                l.second--;
                if( l.second)
                    Q.push_back(l);
            }
            else if( f.first == 0 && l.first == 1){
                pair<int,int> temp = make_pair(1,1);
                Q.push_front(f);
                Q.push_front(temp);
                l.second--;
                S.insert(temp.second);
                if(l.second){
                    Q.push_back(l),S.insert(l.second);
                }
            }
            else if( f.first == 1 && l.second == 0){
                pair<int,int> temp = make_pair(0,1);
                Q.push_front(f);
                Q.push_front(temp);
                l.second--;
                S.insert(f.second);
                if(l.second){
                    Q.push_back(l);
                }
            }

        }
        else{
            if( S.size() == 0){
                printf("0\n");
            }
            else{
                int ans = k >= *(S.rbegin()) ? *(S.rbegin()) : k;
                printf("%d\n",ans);
            }
        }

    }
    return 0;
}
