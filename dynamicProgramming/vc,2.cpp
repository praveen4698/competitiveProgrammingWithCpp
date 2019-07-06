#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define F first
#define S second
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    map<string,int> M;
    map<string,bool> visit;
    string E[1001],A[1001];

    int main()
    {
        int n,m;
        scan2(n,m);
        lp(i,0,n)
        {
            cin>>A[i];
            M[A[i]]++;
            visit[A[i]] = false;
        }
        lp(i,0,m)
        {
            cin>>E[i];
            M[E[i]]++;
            visit[E[i]] = false;
        }
        queue<string> Qp;
        lp(i,0,n)
        {
            if( M[A[i]] == 2)
                Qp.push(A[i]);
        }
        lp(i,0,n)
        {
            if( M[A[i]] == 1)
                Qp.push(A[i]);
        }
        queue<string> Qe;
        lp(i,0,m)
        {
            if( M[E[i]] == 2)
                Qe.push(E[i]);
        }
         lp(i,0,m)
        {
            if( M[E[i]] == 1)
                Qe.push(E[i]);
        }
        int flag = 0;
        while( !Qp.empty() || !Qe.empty())
        {

            if( flag == 0)
            {
                if( Qp.empty())
                {
                    printf("NO\n");
                    break;
                }
                string t = Qp.front();
                Qp.pop();
                if( visit[t] == false)
                {
                    flag =1;
                    visit[t] = true;
                }
               // cout<<t;
               // printf("-- p\n");
            }
            else
            {
                if( Qp.empty())
                {
                    printf("YES\n");
                    break;
                }
                string t = Qe.front();
                Qe.pop();
                if(visit[t ]== false)
                {
                    flag  = 0;
                    visit[t] = true;
                }
               // cout<<t;
               // printf("--e\n");
            }

        }
     /*   if( Qp.empty() && Qe.empty() )
        {
            if( flag == 0)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
        else if( Qp.empty())
        {
            printf("No\n");
        }
        else
            printf("YES\n");*/
        return 0;
    }
