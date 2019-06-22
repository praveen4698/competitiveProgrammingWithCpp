#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
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
        string S;
        cin>>S;
        int n = S.length();
        int flag = 0;
        lp(i,0,n)
            if( (S[i] - '0')%2 == 0)
                flag = 1;
        if(flag == 0)
         {

            printf("-1");
            return 0;
        }



            lp(i,0,n-1)
                if( (S[i]-'0')<(S[n-1]-'0') && (S[i]-'0')%2 == 0)
                {
                    swap(S[i],S[n-1]);
                    cout<<S;
                    return 0;
                }
            lpr(i,n-2,0)
                if( (S[i] - '0')%2 == 0)
                {
                    swap(S[i],S[n-1]);
                    cout<<S;
                    return 0;
                }




        return 0;
    }

