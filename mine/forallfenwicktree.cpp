#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    class fenwick
    {
        vector<int> f;
        public:
        fenwick(int n)
         {
            f.assign(n, 0);
        }
        void update(int i,int val)
        {
            for(;i<f.size();i|=(i+1))
                f[i]+=val;
        }
        int get(int i)
        const
        {
            int res = 0;
            for(;i>=0;i = (i & (i + 1)) - 1)
            {
                res+=f[i];
            }
            return res;
        }
    };
const int lim = 1e5+10;
int bit[lim+1];
void update(int x, int val)
{
      for(; x <= lim; x += x&-x)
        bit[x] += val;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bit[x];
     return sum;
}
    int main()
    {

        return 0;
    }
