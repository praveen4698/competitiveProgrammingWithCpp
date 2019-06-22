#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    const int lim = 1e3+10;
    int min_salary[lim],salary_offered[lim],max_candidate[lim];
    int given_candidate[lim];
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int n,m;
            scanf("%d %d",&n,&m);
            for(int i=0;i<n;++i)
                scanf("%d",&min_salary[i]);
            for(int i=0;i<m;++i)
                scanf("%d %d",&salary_offered[i],&max_candidate[i]);
            for(int i=0;i<m;++i)
                given_candidate[i] = 0;
            long long int ans = 0;
            int cont = 0;
            for(int i=0;i<n;++i)
            {
                string A;
                cin>>A;
                int maxi = -1;
                int index = -1;
                for(int j=0;j<m;++j)
                {
                    //printf("%c")
                    if(A[j] == '1' && salary_offered[j] > maxi && salary_offered[j] >= min_salary[i] && given_candidate[j] < max_candidate[j] )
                    {
                        index = j;
                        maxi = salary_offered[j];
                       // printf("yo");
                    }
                }
                if(maxi != -1)
                {
                    given_candidate[index]++;
                    cont++;
                    ans+=(1LL*maxi);
                }

            }
            int ans2 = 0;
            for(int i=0;i<m;++i)
            {
                if( given_candidate[i] == 0)
                    ans2++;
            }
            printf("%d %lld %d\n",cont,ans,ans2);
        }
        return 0;
    }

