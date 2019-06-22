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

string S;
int main()
{
int t;
scan(t);
while(t--)
{
    cin>>S;
    int n = S.size();
    S = S + "$$$$";
    map<char,int> M;
    int cont = 0;
    for(int i=0;i<n;++i)
    {
        M.clear();
        M[S[i]]++;
        M[S[i+1]]++;
        M[S[i+2]]++;
        M[S[i+3]]++;
        if( M['c'] == 1 && M['h'] == 1 && M['e'] == 1 && M['f'] == 1)
            cont++;

    }
    if(cont == 0)
        cout<<"normal"<<endl;
    else
        cout<<"lovely "<<cont<<endl;
}
return 0;
}


