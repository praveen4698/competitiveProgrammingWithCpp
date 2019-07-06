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

    int C[51],I[51],S[51];
    int main()
    {
        char A[51];
        int n,m;
        scan2(n,m);
        lp(i,0,n+1)
        {
            C[i] = INF;
            I[i] = INF;
            S[i] = INF;
        }
        lp(j,0,n)
        {
            scanf("%s",A);
            lp(i,0,m)
            {
              if( (int)(A[i] - 'a') >= 0 && (int)(A[i] - 'a') <= 25)
                    C[j] = min(C[j],min(i,m-i));
              else if( (int)(A[i] - '0' >= 0) && (int)(A[i]-'0') <= 9)
                    I[j] = min( I[j],min(i,m-i));
              else
                    S[j] = min( S[j],min(i,m-i));
            }
        }
      //  lp(i,0,n)
      //  {
      //      printf("%d %d %d\n",C[i],I[i],S[i]);
      //  }
        int mini = INF;
        lp(i,0,n)
            lp(j,0,n)
                lp(k,0,n)
                {
                    if( C[i] != INF || I[j] != INF || S[k] != INF)
                     {

                        if( i != j && j != k && k != i)
                        {
                            if( C[i] + I[j] + S[k] < mini )
                                mini = C[i] + I[j] + S[k];
                        }

                     }
                }
       printf("%d",mini);
        return 0;
    }
