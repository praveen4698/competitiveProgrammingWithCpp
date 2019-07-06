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


    mci M;
    char A[1001];
    int main()
    {
        int n,flag = 0,maxi;
        scan(n);
        scanf("%s",A);
        if( n%4 != 0)
            flag = 1;
        maxi = n/4;
        lp(i,0,n)
        {
            if( A[i] != '?')
            {
                M[A[i]]++;
                if( M[A[i]] > maxi)
                    flag = 1;
            }
        }
        if( flag  == 1)
            printf("===");
        else
        {
            lp(i,0,n)
            {
                if( A[i] != '?')
                    printf("%c",A[i]);
                else
                {
                    if( M['A'] < maxi)
                    {
                        cout<<'A';
                        M['A']++;
                    }
                    else if( M['C'] < maxi)
                    {
                        cout<<'C';
                        M['C']++;
                    }
                    else if( M['G'] < maxi)
                    {
                        cout<<'G';
                        M['G']++;
                    }
                    else
                    {
                        cout<<'T';

                    }
                }
            }
        }
        return 0;
    }
