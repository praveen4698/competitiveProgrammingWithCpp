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


    int main()
    {
        int cont4 = 0,cont7 = 0,n;
        scan(n);
        cont4 = n/4 + 1;
        int flag = 0 ;
        while(cont4 >= 0)
        {
            if(  4*cont4 + 7*cont7 == n)
            {
                flag = 1;
                break;
            }
            if( 4*cont4 + 7*cont7 > n)
                cont4--;
            else
                cont7++;
        }
        if( flag == 0)
            printf("-1");
        else
        {
            int four = cont4%7;
            int seven = (cont4/7)*4 + cont7;
            lp(i,0,four)
                printf("4");
            lp(i,0,seven)
                printf("7");
        }
        return 0;
    }
