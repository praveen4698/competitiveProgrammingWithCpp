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

const int lim = 1001;
int l[lim],r[lim];
int ret[lim];
int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i)
        scan(l[i]);
    for(int i=0;i<n;++i)
        scan(r[i]);

    int value = n;
    memset(ret,-1,sizeof(ret));
    vector<int> index;
    for(int i=0;i<n;++i){
        index.clear();
        for(int j=0;j<n;++j){
            if( ret[j] == -1 && l[j] == 0 && r[j] == 0){
                index.push_back(j);
            }
        }
        // cout<<"sfa"<<endl;
        if( index.size() == 0)
            break;
        // cout<<index.size()<<endl;
        for(int j = 0;j  < index.size();++j)
        {
            ret[index[j]]  = value;
        }
        value--;
        for(int j=0;j<index.size();++j){
            int x = index[j];
            for(int k = 0;k<x;++k){
                if( ret[k] == -1)
                    r[k]--;
            }
            for(int k=x+1;k<n;++k)
                l[k]--;
        }


    }
    int flag = 0;
    for(int i=0;i<n;++i)
        if( ret[i] == -1)
            flag = 1;
    if( flag == 1)
        printf("NO\n");
    else{
        printf("YES\n");
        for(int i=0;i<n;++i)
            printf("%d ",ret[i]);
    }
    return 0;
}

