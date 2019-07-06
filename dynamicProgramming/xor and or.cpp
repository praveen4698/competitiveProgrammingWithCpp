#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b) scanf("%d %d %d",&a,&b,&c)
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

    char A[1000001];
    char B[1000001];
    int main()
    {
        scanf("%s",A);
        scanf("%s",B);
        int n1 = strlen(A);
        int n2 = strlen(B);
        int flag = 0;
        if( n1 != n2)
            flag = 1;

        int counti = 0;
        lp(i,0,n1)
        {
            if( A[i] == '0')
                counti++;
        }
        if( counti == n1)
            flag = 1;
        int count2 = 0;
        lp( i ,0,n2)
        {
            if( B[i] == '0')
                count2++;
        }
        if( count2 == n2)
            flag = 1;

        if( count2 == n2 && counti == n1 && n1 == n2)
            flag = 0;

        if( flag == 1)
            printf("NO");
        else
            printf("YES");
        return 0;
    }
