#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef set<int> si;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6;
    si A[lim];
    int main()
    {
        string S;
        cin>>S;
        int n = S.length();
        si::iterator it;
        A[0].insert(0);
        if( n < 3)
        {
            printf("Just a legend");
            return 0;
        }
        si fnl;
        lp(i,1,n)
        {
            A[i].insert(0);
            for(it = A[i-1].begin();it != A[i-1].end();++it)
            {
                if( S[i] == S[*it])
                {
                    A[i].insert(*it + 1);
                }
                fnl.insert(*it);
            }
            if( i >= 2)
                A[i-2].clear();
        }

      /*  lp(i,1,n-1)
        {
            for(it = A[i].begin();it != A[i].end(); ++it)
            {
                fnl.insert(*it );
            }
        } */
        vi ans;
        set_intersection(fnl.begin(),fnl.end(),A[n-1].begin(),A[n-1].end(),back_inserter(ans));
        if( *ans.rbegin() == 0)
            printf("Just a legend");
        else
        {
            int f = *ans.rbegin();
            lp(i,0,f)
                printf("%c",S[i]);
        }
        return 0;
    }
