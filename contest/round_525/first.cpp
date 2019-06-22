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

vector<int> op;
vector<pair<int,int> > ans;
vector<int> A;
int main()
{
    int n;
    scan(n);
    A.resize(n);
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    int flag = 0;
    for(int i=1;i<n;++i){
        if( A[i] >  A[i-1])
            flag++;
    }
    if( flag == n-1){
        cout<<"0"<<endl;
        return 0;
    }
    reverse(all(A));
    int prev = 0;
    int cont = n+1;
    for(int i=0;i<n;++i){
        int rem = n-i-1;
        A[i]+=prev;
        int temp = A[i]%n;
        cont--;
        if( rem == temp)
            continue;
        int add = 0;
        if( rem > temp){
            add = rem-temp;
        }
        else{
            add = n-temp+rem;
        }
        op.push_back(1);
        ans.push_back(make_pair(cont,add));
        prev+=add;
    }
    if( op.size() > 0){
        op.push_back(2);
        ans.push_back(make_pair(n,n));
    }
    cout<<op.size()<<endl;
    for(int i=0;i<op.size();++i){
        printf("%d %d %d\n",op[i],ans[i].first,ans[i].second);
    }
    return 0;
}
