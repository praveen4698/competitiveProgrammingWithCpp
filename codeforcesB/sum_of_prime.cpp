#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int A[21][21];
    int main()
    {
        int ans = 0;
        for(int i=0;i<20;++i)
        {
            for(int j=0;j<20;++j)
            {
                string s;
                cin>>s;
                int t=0;
                int r = 1;
                for(auto S:s)
                {
                    t = r*t + ((int)(S-'0'));
                    r = 10*r;
                }
                A[i][j] = t;
            }
        }
        for(int i=0;i<20;++i)
        {
            for(int j=0;j<20;++j)
            {
                int temp1 = 1;
                int temp2 = 1;
                int temp3 = 1;
                int cont1 = 0;
                int cont2 = 0;
                int cont3 = 0;
                int temp4 = 1;
                int cont4 = 0;
                for(int k=0;k<4;++k)
                {
                    if( i+k < 20)
                        temp1*=A[i+k][j],cont1++;
                    if(j+k < 20)
                        temp2*=A[i][j+k],cont2++;
                    if(i+k < 20 && j+k < 20)
                        temp3*=A[i+k][j+k],cont3++;
                    if( i-k >= 0 && j+k < 20)
                        temp4*=A[i-k][j+k],cont4++;
                }
                if(cont1 == 4 && ans< temp1)
                    ans = temp1;
                if( cont2 == 4 && ans < temp2)
                    ans = temp2;
                if( cont3 == 4 && ans < temp3)
                    ans = temp3;
                if(cont4 == 4 && ans < temp4)
                    ans = temp4;
            }
        }
        cout<<ans;
        return 0;
    }
