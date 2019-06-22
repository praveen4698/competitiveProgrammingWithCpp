#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    vector<pair<int,int> > A;
    vector<int> ans(2111);
    struct comp
    {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
        {
            return lhs.second-lhs.first < rhs.second-rhs.first;
        }
    };

    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,k;
            A.clear();
            scanf("%d %d",&n,&k);
            for(int i=0;i<n;++i)
                ans[i] = 0;
            for(int i=0;i<k;++i)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                A.push_back({a,b});

            }
            for(int i=1;i<A.size();++i)
            {
                for(int j=0;j<i;++j)
                {
                    if( A[j].first >= A[i].first && A[j].first <= A[i].second && A[j].second >= A[i].second )
                    {
                        A.push_back({A[i].first,A[j].first-1});
                        A.push_back({A[j].first,A[i].second});
                        A.push_back({A[i].second+1,A[j].second});

                        A.erase(A.begin()+i);
                        A.erase(A.begin()+j);
                        i-=2;
                    }
                    else if( A[i].first >= A[j].first && A[i].first <= A[j].second && A[i].second >= A[j].second )
                    {
                        A.push_back({A[j].first,A[i].first-1});
                        A.push_back({A[i].first,A[j].second});
                        A.push_back({A[j].second+1,A[i].second});

                        A.erase(A.begin()+j);
                        A.erase(A.begin()+i);
                        i-=2;
                    }
                }
            }
            A.push_back({0,n-1});
            sort(A.begin(),A.end(),comp());
            for(int i=0;i<A.size();++i)
            {
                int cnt = 0;
                for(int j=A[i].first;j<=A[i].second;++j)
                    if(ans[j] == 0)
                        cnt++;
                int ch = 0;
                for(int j=A[i].first;j<=A[i].second;++j)
                {
                    if(ans[j]== 0 && ch < cnt/2)
                        ans[j] = 1,ch++;
                    else if(ans[j] == 0 && ch >= cnt/2)
                        ans[j] = -1;
                }
            }
            for(int i=0;i<n;++i)
                if( ans[i] == 0)
                    ans[i] = 1;
            for(int i=0;i<n;++i)
            {
                if( ans[i] == 1)
                    printf("(");
                else
                    printf(")");
            }
            printf("\n");
        }
        return 0;
    }

