#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int a,b,h,w,n;
        scanf("%d %d %d %d %d",&a,&b,&h,&w,&n);
        vector<int> A;
        for(int i=0;i<n;++i)
        {
            int a;
            scanf("%d",&a);
            A.push_back(a);
        }
        sort(A.begin(),A.end());
        reverse(A.begin(),A.end());
        int cont=0,flag = 0;
        for(int i : A)
        {
           // printf("%d\n",i);
            if( (h >= a && w >= b) || (h >= b && w >= a) )
            {
                flag = 1;
                break;
            }
            if( float(a/h) > float(b/w))
            {
                h = h*i;
                cont++;
            }
            else
            {
                w = w*i;
                cont++;
            }
        }
        if(flag == 1)
            printf("%d",cont);
        else
            printf("-1");
        return 0;
    }
