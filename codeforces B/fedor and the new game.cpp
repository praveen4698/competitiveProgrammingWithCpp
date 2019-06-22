#include<bits/stdc++.h>
using namespace std;
#define loop(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int main()
    {
        vi A(1001);
        int n,m,k;
        cin>>n>>m>>k;
        int i;
        loop(i,0,m)
        {
            cin>>A[i];
        }
        int num ;
        cin>>num;
        int count = 0;
        loop(i,0,m)
        {
            int j;
            int temp = 0;
            loop(j,0,n)
            {
                if( (num & (1<<j)) && (( A[i] & (1<<j)) == 0))
                {
                    temp++;
                }
                else if( ((num & (1<<j)) == 0) && ( A[i] & (1<<j)))
                {
                    temp++;
                }
            }
            if( temp <= k)
            {
                count = count + 1;
            }

        }

        cout<<count;
        return 0;
    }
