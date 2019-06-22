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


int main()
{
    int t;
    scan(t);
    while(t--){
        int n;
        scan(n);
        string start;
        cin>>start;
        int zero = 0,one = 0;
        int change = 0;
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            int m = s.size();
            for(int i=1;i<m;++i){
                if( s[i] != s[i-1])
                    change++;
            }
            if( s[m-1] == '0')
                zero++;
            else
                one++;
        }
        if( start[2] == 'e'){
            if( zero > one)
                cout<<"Dum"<<endl;
            else
                cout<<"Dee"<<endl;
        }
        else{
            if( one > zero)
                cout<<"Dee"<<endl;
            else
                cout<<"Dum"<<endl;
        }

    }

    return 0;
}


