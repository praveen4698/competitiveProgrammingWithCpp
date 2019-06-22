#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 1e5+10;
    int A[lim];
    map<int,int> diff;
    vector<int> a;
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            a.clear();
            diff.clear();
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                scanf("%d",&A[i]);
                if(i > 0)
                {
                    a.push_back(A[i]-A[i-1]);
                    diff[A[i]-A[i-1]]++;
                }
            }
            if( n == 3)
            {
                printf("%d\n",min(A[0],min(A[1],A[2])));
                continue;
            }
            if( diff.size() >= 4)
            {
                printf("-1\n");
                continue;
            }
            if( diff.size() == 1)
            {
                printf("%d\n",min(A[0],A[n-1]));
                continue;
            }
            if(diff.size() == 2 || diff.size() == 3)
            {
                map<int,int> temp;
                for(int i=2;i<n;++i)
                    temp[A[i]-A[i-1]]++;
                if(temp.size()==1)
                {
                    printf("%d\n",A[0]);
                    continue;
                }
                temp.clear();
                for(int i=1;i<n-1;++i)
                    temp[A[i]-A[i-1]]++;
                if( temp.size()== 1)
                {
                    printf("%d\n",A[n-1]);
                    continue;
                }


                int d = 0;
                for(auto it:diff)
                {
                    d = max(d,it.first);
                }
                int flag = 0;
                int ans = -1;
                for(int i=1;i<n-1;++i)
                {
                    if( A[i]-A[i-1] == d)
                        continue;
                    if( A[i+1]-A[i-1] == d)
                    {
                        flag = 1;
                        ans = A[i];
                    }
                }
                if( flag == 1)
                {
                    printf("%d\n",ans);

                }
                else
                    printf("-1\n");

            }
        }
        return 0;
    }
