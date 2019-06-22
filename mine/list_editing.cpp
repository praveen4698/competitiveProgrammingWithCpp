#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int dp[101][101];
    int A[101],B[101];
    int n,m;
    int solve(int i,int j)
    {
        if( i == n && j == m)
            return 0;
        if( dp[i][j] != -1)
            return dp[i][j];
        if( i == n)
            return (m-j);
        if( j == m)
            return (n-i);
        if( A[i] == B[j])
            return dp[i][j] = solve(i+1,j+1);
        else
        {
            return dp[i][j] = 1+min(solve(i,j+1),min(solve(i+1,j),solve(i+1,j+1)));
        }
    }
    int main()
    {

        int t;
        cin>>t;
        while(t--)
        {
           // int n;
            cin>>n;
            for(int i=0;i<n;++i)
                cin>>A[i];
           // int m;
            cin>>m;
            for(int i=0;i<m;++i)
                cin>>B[i];
            for(int i=0;i<n+1;++i)
                for(int j=0;j<m+1;++j)
                    dp[i][j] = -1;
            cout<<solve(0,0)<<endl;
        }
        return 0;
    }
