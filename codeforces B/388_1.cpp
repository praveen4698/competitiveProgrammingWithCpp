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


    int main()
    {
        int n;
        scan(n);
        char S[200001];
        scanf("%s",S);
        queue<int> dp,rp;
        bool visited[200001];
        lp(i,0,n)
         {
             visited[i] = false;
             if( S[i] == 'R')
                rp.push(i);
             else
                dp.push(i);
         }
         int i = 0;
         if( rp.empty())
         {
             printf("D");
             return 0;
         }
         if( dp.empty())
         {
             printf("R");
             return 0 ;
         }
         while(1)
         {
             int flag = 0;
             if( visited[i] == false)
             {
                  if( dp.empty())
                 {
                     printf("R");
                     flag = 1;
                     break;
                 }

                 if( S[i] == 'R')
                 {

                     int t = dp.front();
                     dp.pop();
                     visited[t] = true;
                 }
                  if( rp.empty())
                 {
                     flag = 1;
                     printf("D");
                     break;
                 }
                 if( S[i] == 'D')
                 {
                     int t = rp.front();
                     rp.pop();
                     visited[t] = true;

                 }

             }
             i++ ;
             if( i == n)
                i = 0;

             if( flag == 1)
                break;
         }
        return 0;
    }
