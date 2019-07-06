#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    int solve(string S)
    {
        int cont = 0;
        for(int i=1; i<=S.size()/2; i++)
        {
            int flag =1;
            for(int j=0; j<i; j++)
            {
                if(S[j]!=S[i+j])
                    flag =0;
            }

            if(flag==1)
                cont++;
        }
        return cont;
    }
    int main()
    {
        string A;
        cin>>A;
        cout<<solve(A);
        return 0;
    }
