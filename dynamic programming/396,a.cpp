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

    mii M1,M2;
    int main()
    {
        string S,A;
        cin>>S;
        cin>>A;
        int n1 = S.length();
        int n2 = A.length();
        lp(i,0,n1)
            M1[S[i]-'a']++;
        lp(i,0,n2)
            M2[A[i]-'a']++;
        int flag = 0;
        int maxi = max(n1,n2);
        lp(i,0,26)
        {
            if( M1[i] != M2[i])
            {
                flag = 1;
                break;
            }
        }
        if( flag == 0)
            printf("-1");
        else
            printf("%d",maxi);
        return 0;
    }
