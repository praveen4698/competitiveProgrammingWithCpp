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
        string S1,S2;
        cin>>S1;
        cin>>S2;
        int n1 = S1.length();
        int n2 = S2.length();
        int cont = 0;
        lp(i,1,min(n1,n2)+1)
        {
            if(n1%i != 0 || n2%i != 0)
                continue;
            int flag = 0;
            lp(j,1,i+1)
                if(S1[j-1] != S2[j-1])
                    flag = 1;

            if( flag == 1)
                continue;

            lp(j,i+1,n1+1)
                if( S1[j-1] != S1[j-1-i])
                    flag = 1;

            if(flag == 1)
                continue;

            lp(j,i+1,n2+1)
                if( S2[j-1] != S2[j-i-1])
                    flag = 1;

            if(flag == 1)
                continue;

            cont++;
        }
        printf("%d",cont);
        return 0;
    }

