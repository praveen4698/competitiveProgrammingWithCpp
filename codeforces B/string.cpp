#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;


int main()
{
    int t;
    scan(t);
    map<char,int> M1,M2;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        M1.clear(),M2.clear();
        for(auto b:B)
            M2[b]++;
        int ans = INF;
        pair<int,int> index;
        int i=0;
        for(int j=0;j<A.size()+1;++j)
        {
            if( j < A.size())
            {

                char a = A[j];
                M1[a]++;
            }
            int flag = 0;
            for(auto m:M2)
            {
                if( M1[m.first] < m.second)
                    flag = 1;
            }
            if( flag == 0)
            {
                while( i<=j)
                {
                    if( ans > (j-i+1))
                    {
                        index.fi = i;
                        index.se = j;
                        ans = j-i+1;
                    }
                    char b = A[i];
                    M1[b]--;
                    i++;
                    if( M1[b] < M2[b])
                        break;
                }

            }

        }
        /*int n = A.size();
        while( i<A.size())
        {
                if( ans > (n-i+1))
                {
                    index.fi = i;
                    index.se = n;
                    ans = n-i+1;
                }
                char b = A[i];
                M1[b]--;
                i++;
                if( M1[b] < M2[b])
                    break;
        } */
        if( ans == INF)
            cout<<"-1";
        else
        {
            for(int i=index.fi;i<=index.se;++i)
                cout<<A[i];
        }
        cout<<endl;
    }
    return 0;
}


