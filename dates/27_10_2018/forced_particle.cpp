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
const int lim = 101;
int l[lim],down[lim];
string S[lim];
// int row[lim],col[lim];
int ret[lim][lim];
string A;
int main()
{
    int t;
    scan(t);
    while(t--){
        int n,m;
        scan2(n,m);
        // memset(row,0,sizeof(row));
        // memset(col,0,sizeof(col));
        for(int i=0;i<n;++i){
            cin>>S[i];
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if( S[i][j] == '1'){
                    l[i]++;
                    down[j]++;
                }
            }
        }
        cin>>A;
        int len = A.size();
        memset(ret,0,sizeof(ret));
        for(int i=1;i<len;++i){
            if( A[i] == 'L' || A[i] == 'R'){
                
                if(A[i-1] == 'D' || A[i-1] == 'U' ){
                    memset(l,0,sizeof(l));
                    for(int j=0;j<m;++j){
                        l[down[i]]++;
                    }
                    if(A[i-1] == 'D' ){
                        for(int j=n-2;j>=0;--j){
                            l[j]+=l[j-1];
                        }
                    }
                    else{
                        for(int j=1;j<n;++j){
                            l[j]+=l[j-1];
                        }
                    }
                }
            }
            else if(A[i] == 'D' || A[i] == 'U'){

                if( A[i-1] == 'L' || A[i-1] == 'R'){
                    memset(down,0,sizeof(down));
                    for(int j=0;j<n;++j){
                        down[l[j]]++;
                    }
                    if( A[i-1] == 'L'){
                        for(int j=m-2;j>=0;--j){
                            down[j]+=down[j+1];
                        }
                    }
                    else{
                        for(int j=1;j<n;++j){
                            down[j]+=down[j-1];
                        }
                    }
                }
            }
        }

        if( A[len-1] == 'L'){
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    if( l[i] > 0){
                        cout<<"1";
                        l[i]--;
                    }
                    else{
                        cout<<"0";
                    }
                }
                cout<<endl;
            }
        }
        else if( A[len-1] == 'R'){
            for(int i=0;i<n;++i){
                l[i] = m - l[i];
                for(int j=0;j<m;++j){
                    if( l[i] > 0){
                        cout<<"0";
                        l[i]--;
                    }
                    else{
                        cout<<"1";
                    }
                }
                cout<<endl;
            }
        }
        else if( A[len-1] == 'D'){
            for(int i=n-1;i>0;--i){
                for(int j=0;j<m;++j ){
                    if( down[j] > 0){
                        ret[i][j] = 1;
                        down[j]--;
                    }
                }
            }
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    cout<<ret[i][j];
                }
                cout<<endl;
            }
        }
        else{
            
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j ){
                    if( down[j] > 0){
                        ret[i][j] = 1;
                        down[j]--;
                    }
                }
            }

            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    cout<<ret[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
