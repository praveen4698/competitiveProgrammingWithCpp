#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
int A[lim];
int sum[lim];
int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n,d;
        S2(n,d);
        sum[0] = 0;
        int flag = 0;

        for(int i=1;i<=n;++i)
        {
            S(A[i]);
            sum[i] = sum[i-1]+A[i];
            if(A[i] >= d)
                flag = 1;

        }
        if( flag == 1)
        {
            cout<<"1"<<endl;
            continue;
        }
        if( d <= 0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int ans = n+10;
       // int sum = 0;
        int j = 1;
        int i;
        for( i=1;i<=n;++i)
        {
            while(sum[i]-sum[j-1] >= d && i >= j)
            {
                ans = min(ans,i-j+1);
                j++;
            }
          //  cout<<ans<<endl<<"i =  "<<i<<" j= "<<j<<endl;
            while(sum[i]-sum[j-1] <= 0 && i>=j)
                j++;
            while( A[j] <= 0 && i>=j)
                j++;
          //  cout<<sum[i]-sum[j-1]<<endl;
            while(sum[i]-sum[j-1] >= d && i >= j)
            {
                ans = min(ans,i-j+1);
                j++;
                while(A[j] <= 0 && i>=j)
                    j++;
            }
            while(sum[i]-sum[j-1] <= 0 && i>=j)
                j++;
            while( A[j] <= 0 && i>=j)
                j++;
          //  cout<<sum[i]-sum[j-1]<<endl;
            while(sum[i]-sum[j-1] >= d && i >= j)
            {
                ans = min(ans,i-j+1);
                j++;
                while(A[j] <= 0 && i>=j)
                    j++;
            }
          //  cout<<ans<<endl<<"i =  "<<i<<" j= "<<j<<endl<<endl;
        }

        while(n>=j)
        {
            if( sum[n]-sum[j-1] >= d)
                ans = min(ans,n-j+1);
            j++;
        }
        if( ans < n+1)
            cout<<ans<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
