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

    char A[100001];
    map<char,int> M,S;
    int main()
    {
        M['B'] = 1;
        M['u'] = 2;
        M['l'] = 1;
        M['b'] = 1;
        M['a'] = 2;
        M['s'] = 1;
        M['r'] = 1;
        scanf("%s",A);
        int n = strlen(A);
        lp(i,0,n)
        {
            S[A[i]]++;
        }
        string temp = "Bulbasaur";
        int mini = INF;
        lp(i,0,9)
        {
            int t = S[temp[i]]/M[temp[i]];
            if( t < mini)
                mini = t;
        }
        printf("%d\n",mini);

        return 0;
    }
