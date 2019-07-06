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
        string A;
        int n,t;
        cin>>n>>t;
        cin>>A;
        int i;
        while(t--)
        {


        loop(i,0,n-1)
        {
            if( A[i] == 'B' && A[i+1] == 'G')
            {
                A[i] = 'G';
                A[i+1] = 'B';
                i++;
            }
        }
        }
        cout<<A;
        return 0;
    }
