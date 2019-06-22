#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        string S;
        cin>>S;
        int n = S.size();
        int cont = 0;
        for(int i = 0;i < n/2 ;++i)
        {
            if( S[i] != S[n-i-1])
                cont++;
        }
         if( n == 1)
            printf("YES\n");
        else if( n%2 == 1 && cont == 0)
            printf("YES\n");
        else if(cont == 1)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }
