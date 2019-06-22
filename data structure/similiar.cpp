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
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    map<string,int> M;
    int main()
    {
        int t;
        scan(t);
        while(t--)
        {
            string a;
            lp(i,0,8)
            {
                cin>>a;
                M[a]++;
            }
            map<string,int>::iterator it;
            int cont =0;
            for(it = M.begin();it != M.end();++it)
            {
                if( (*it).second >= 2)
                    cont++;
            }

            if(cont > 1)
                printf("similar\n");
            else
                printf("dissimilar\n");

            M.clear();
        }
        return 0;
    }


