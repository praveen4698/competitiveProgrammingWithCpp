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
        ll count = 0;
        vi city(123456);
        ll sum = 0;
        vi A(123456);
        int k,n;
        cin>>n>>k;
        int i;
        loop(i,1,n+1)
        {
            cin>>A[i];
            sum = sum + A[i];
        }
        A[0] = A[n];
        A[n+1] = A[1];
      //  cout<<count<<"\n";
      //  cout<<sum<<"\n";
        loop(i,2,n+1)
        {
            count =  count + A[i]*A[i-1];
        }
        count = count + A[1]*A[n];
        //cout<<count<<"\n";
        loop(i,0,k)
        {
            cin>>city[i];
        }
        //sort(city.begin(),city.end());
        loop(i,0,k)
        {
          // cout<<city[i]<<"\n";
           count = count + A[city[i]]*(sum - A[city[i]] - A[city[i] -1] - A[city[i] +1]);
           sum = sum - A[city[i]];
           A[city[i]] = 0;
           if( city[i] == 1)
           {
               A[n+1] = 0;
           }
           if( city[i] == n)
           {
               A[0] = 0;
           }

        }
        cout<<count;
        return 0;
    }
