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
//#define S second
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
    pair<string,string> S[1001];
    int mark[1001];
    int main()
    {
        int n;
        scan(n);
        lp(i,0,n)
        {
            mark[i] = 0;
            string a,b;
            cin>>a;
            cin>>b;
            S[i].F.push_back(a[0]);
            S[i].F.push_back(a[1]);
            S[i].F.push_back(a[2]);
            S[i].second.push_back(a[0]);
            S[i].second.push_back(a[1]);
            S[i].second.push_back(b[0]);

        }
        lp(i,0,n)
        {
            //cout<<S[i].F;
         //   printf("\n");
         //  cout<<S[i].second;
         //   printf("\n");
        }
        lp(i,0,n)
        {
            lp(j,0,n)
            {
                if( i != j && S[i].F.compare(S[j].F) == 0 )
                {

                   if( mark[i] == 0)
                        M[S[i].second]++;
                   if( mark[j] == 0)
                        M[S[j].second]++;
                    mark[i] = 1;
                    mark[j] = 1;

                    if( M[S[i].second] > 1 || M[S[j].second] > 1)
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
            }

        }
        lp(i,0,n)
        {
            lp(j,0,n)
            {
                if( mark[j] == 0 && M[S[j].F] == 1 )
                {
                    mark[j] = 1;
                    M[S[j].second]++;
                    if( M[S[j].second] > 1)
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
            }
        }
        printf("YES\n");
            lp(i,0,n)
            {
                if( mark[i] == 1)
                    cout<<S[i].second;
                else
                    cout<<S[i].F;
                printf("\n");
            }
        return 0;
    }
