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

    string A[52];
    int main()
    {
        int n,k;
        int S[52];
        lp(i,0,52)
            S[i] = 0;
        scan2(n,k);
        lp(i,0,n-k+1)
            cin>>A[i];

        int cont = 1;
        lp(i,0,n-k+1)
        {
            if( A[i][0] == 'Y' )
            {
                lp(j,i,i+k)
                {
                    if( S[j] == 0)
                    {
                        S[j] = cont;
                        cont++;

                    }
                }
            }
            else
            {
                int flag = 0;
                lp(j,i,i+k)
                {
                    if( j >= i+1 && S[j] == S[j-1])
                    {
                        flag++;
                    }
                    else if( j >= i+1 && S[j] == 0)
                    {
                        S[j] = S[j-1];
                        flag = 2;

                    }
                    else if( S[j] == 0)
                    {
                        S[j] = cont;
                        flag++;
                    }
                    if( flag == 2)
                    {
                        cont = S[j] +1;
                        break;
                    }
                }
            }


        }
        lp(i,0,n)
            {
                if( S[i] <= 26)
                {
                    printf("A");
                }
                else
                {
                    printf("B");
                }
                    int a = S[i]%26;
                    if( a == 0)
                        printf("z ");
                    else
                        printf("%c ",96+a);

            }
        return 0;
    }
