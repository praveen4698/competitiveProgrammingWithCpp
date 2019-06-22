#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    vector<int> A,B,ans;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            A.clear();
            B.clear();
            ans.clear();
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                int a;
                scanf("%d",&a);
                A.push_back(a);
                B.push_back(a);
                ans.push_back(a);
            }
            int k=15;
            int mini = 0;
            while(k--)
            {
                random_shuffle(B.begin(),B.end());
                int temp = 0;
                for(int i=0;i<n;++i)
                {
                    if( A[i] != B[i] )
                        temp++;
                }
                if( temp > mini)
                {
                    mini = temp;
                    for(int i=0;i<n;++i)
                        ans[i] = B[i];
                }
            }
            cout<<mini<<endl;
            for(int i=0;i<n;++i)
                printf("%d ",ans[i]);
            cout<<endl;
        }
        return 0;
    }
