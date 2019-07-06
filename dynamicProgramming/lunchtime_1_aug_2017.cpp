#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int A[30];
            for(int i=0;i<26;++i)
                scanf("%d",&A[i]);
            int ans = 0;
            string S;
            cin>>S;
            int cont[26] ;
            for(int i=0;i<26;++i)
                cont[i] = 0;
            for(int i=0;i<S.length();++i)
                cont[S[i]-'a']++;
            for(int i=0;i<26;++i)
                if(cont[i] == 0)
                    ans+=A[i];
            printf("%d\n",ans);
        }
        return 0;
    }
