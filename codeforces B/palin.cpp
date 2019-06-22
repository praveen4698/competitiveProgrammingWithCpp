#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e6+10;
    int ans[lim+10],A[lim+10];
    int main()
    {
        vector<int> temp1,temp2;
        int prev = 101101;
        memset(A,0,sizeof(A));
        for(int i=100;i<1000;++i)
            for(int j=100;j<1000;++j)
                A[i*j] = 1;
        for(int i=101101;i<lim;++i)
        {
            temp1.clear();
            temp2.clear();
            int j = i;
            while(j!=0)
            {
                temp1.push_back(j%10);
                temp2.push_back(j%10);
                j=j/10;
            }
            int flag = 0;
            reverse(temp2.begin(),temp2.end());
            for(int j=0;j<temp1.size();++j)
                if(temp2[j] != temp1[j])
                    flag = 1;
            if( flag == 0 && A[i] == 1)
            {

                ans[i] = prev;
                prev = i;
            }
            else
                ans[i] = prev;
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n;
            cin>>n;
            cout<<ans[n]<<"\n";
        }
        return 0;
    }
