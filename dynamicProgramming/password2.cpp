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
typedef set<int> si;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

const int lim = 2e6;
char pat[lim];
int lps[lim];
void computeLPSArray( int M)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

    int main()
    {
        scanf("%s",pat);
        int n = strlen(pat);
        if( n <= 2)
        {
            printf("Just a legend");
            return 0;
        }
        computeLPSArray(n);
        si fnl;
       // printf("%d\n",n);
        lp(i,1,n)
        {
          //  printf("%d %c\n",i,pat[i]);
        }
        lp(i,1,n-1)
        {
          // printf("%d = %d \n",i,lps[i]);
            fnl.insert(lps[i]);
        }
        while(lps[n-1] > 0)
        {
          // printf("%d\n",lps[n-1]);
            si::iterator it;
            int flag = 0;
            for(it = fnl.begin(); it != fnl.end() ;++it)
            {
                if( *it == lps[n-1])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;

            lps[n-1] = lps[lps[n-1] - 1] ;
           // printf("%d",lps[n-1]);
        }
      //  printf("%d",lps[n-1]);
        if( lps[n-1] <= 0)
            printf("Just a legend");
        else
        {
           // printf("%d\n",lps[n-1]);
            lp(i,0,lps[n-1])
                printf("%c",pat[i]);
        }
        return 0;
    }
