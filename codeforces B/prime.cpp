#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e8;
    int A[lim];
    vector<int> primes;
    void preprocess()
    {
        memset(A,0,sizeof(A));
        for(int i=2;i<lim;++i)
        {
            if(A[i] == 0)
            {
                for(int j=2*i;j<lim;j=j+i)
                    A[j] = 1;
            }
        }
        for(int i=2;i<lim;++i)
            if(A[i]==0)
                primes.push_back(i);
    }
    int ans[lim];
    int main()
    {
        preprocess();
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            scanf("%d",&n);
            cout<<primes[n-1]<<"\n";
        }
        return 0;
    }
