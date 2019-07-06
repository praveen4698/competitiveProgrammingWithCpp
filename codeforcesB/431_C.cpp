#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int k;
        scanf("%d",&k);
        int x = k;
        vector<int> ans;
        if(k==0)
        {
            printf("ab");
            return 0;
        }
        while(x>0)
        {
            int cont = 1;
            int r = 2;
            while(x>0)
            {
               /* if( x == cont)
                {
                    x-=cont;
                    break;
                } */
                if(cont > x)
                    break;

                cont+=r;
                r++;
            }
            x-=(cont-r+1);
            ans.push_back(cont-r+1);
        }
        map<int,int> M;
        int cont = 1;
        int r = 2;
        for(int i=1;i<100000;++i)
        {
            M[cont] = i+1;
            cont+=r;
            r++;
        }

        for(int i=0;i<ans.size();++i)
        {
            //cout<<ans[i];
            for(int j=0;j<M[ans[i]];++j)
                printf("%c",i+'a');
        }
        return 0;
    }
