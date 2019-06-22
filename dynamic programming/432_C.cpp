#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e3+10;
    struct node
    {
        int a,b,c,d,e;
        node():a(0),b(0),c(0),d(0),e(0){};

    };
    node G[lim];

    void val(node &AB,node A,node B)
    {
        AB.a = A.a - B.a;
        AB.b = A.b - B.b;
        AB.c = A.c - B.c;
        AB.d  = A.d - B.d;
        AB.e = A.e - B.e;
    }
    int acute(node A, node B,node C )
    {
        node AB;
        val(AB,A,B);
        node AC;
        val(AC,A,C);
        double dot = 1.00*AB.a*AC.a + 1.00*AB.b*AC.b + 1.00*AB.c*AC.c + 1.00*AB.d*AC.d + 1.00*AB.e*AC.e;
        double mode_ab = sqrt(1.00*AB.a*AB.a + 1.00*AB.b*AB.b + 1.00*AB.c*AB.c + 1.00*AB.d*AB.d + 1.00*AB.e*AB.e);
        double mode_ac = sqrt(1.00*AC.a*AC.a + 1.00*AC.b*AC.b + 1.00*AC.c*AC.c + 1.00*AC.d*AC.d + 1.00*AC.e*AC.e);
        double ans = dot/(mode_ab*mode_ac);
      //  cout<<ans<<endl;
        double ang = acos(ans) * 180.0 / PI;
        if( ang >= 0.0000000 && ang < 90.0000000)
            return 1;
        else
            return 0;
    }
    bool good[lim];
    int main()
    {
        int n;
        scanf("%d",&n);
        vector<int> ans;
        for(int i=0;i<n;++i)
        {
            scanf("%d %d %d %d %d",&G[i].a,&G[i].b,&G[i].c,&G[i].d,&G[i].e);
            ans.push_back(i);
            good[i] = true;
        }
        int cont = 0;
        if(n <3)
        {
            printf("%d\n",n);
            for(int i=0;i<n;++i)
            {
                printf("%d\n",i+1);
            }
            return 0;
        }

        while(cont < 20000 )
        {
            cont++;
            random_shuffle(ans.begin(),ans.end());

            node A = G[ans[0]];
            node B = G[ans[1]];
            node C = G[ans[2]];
          //  printf("%d %d %d\n",ans[0],ans[1],ans[2]);
            if( acute(A,B,C) == 1)
                good[ans[0]] = false;
            if( acute(B,A,C) == 1)
                good[ans[1]] = false;
            if( acute(C,A,B) == 1)
                good[ans[2]] = false;

        }
        int k =0;
        for(int i=0;i<n;++i)
        {
            if( good[i] == true)
                k++;
        }
        printf("%d\n",k);
        for(int i=0;i<n;++i)
        {
            if(good[i] == true)
                printf("%d\n",i+1);
        }
        return 0;
    }
