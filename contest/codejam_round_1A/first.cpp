#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%d %d",&a,&b);
#define scan3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define print(x) printf("%d\n",x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 101;
int row[lim],col[lim];
string A[lim];
int n,m;
int solve(int value,int h,int v)
{
    vector<int> part1;
    part1.pb(0);
    int cont = 0;
    int cut = 0;
    for(int i=0;i<n;++i)
    {
        cont+=row[i];
        if( cont != 0 && cont == (v+1)*value)
        {
            cut++;
            cont = 0;
            part1.pb(i+1);
        }

    }
  //  cout<<"cut = "<<cut<<" "<<v<<endl;
    if(cut != h+1)
        return 1;
  //  cout<<"asfa"<<endl;
    vector<int> part2;
    part2.pb(0);
    cont = 0;
    cut = 0;
    for(int i=0;i<m;++i)
    {
        cont+=col[i];
        if( cont != 0 && cont == (h+1)*value)
        {
            cut++;
            cont = 0;
            part2.pb(i+1);
        }
    }
  //  cout<<"cut = "<<cut<<" "<<h<<endl;
    if( cut != v+1)
        return 1;
    int a = part1.size();
    int b  = part2.size();
    for(int i=0;i<a-1;++i)
    {
        for(int j=0;j<b-1;++j)
        {
            int r1 = part1[i];
            int r2 = part1[i+1];
            int c1 = part2[j];
            int c2 = part2[j+1];
            int temp = 0;
        //   printf("%d %d %d %d \n",r1,r2,c1,c2);
            for(int r=r1;r<r2;++r)
            {
                for(int c=c1;c<c2;++c)
                {
                    if( A[r][c] == '@')
                        temp++;
                }
            }
          // cout<<"temp = "<<temp<<"value="<<value<<endl;
            if(temp != value)
                return 1;

        }
    }
    return 0;
}
int main()
{
    int t;
    scan(t);
    int xx =1 ;
    while(t--)
    {
        int v,h;
        scan2(n,m);
        scan2(h,v);
        for(int i=0;i<n;++i)
        {
            cin>>A[i];
        }
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        int cont = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if( A[i][j] == '@')
                {
                    cont++;
                    row[i]++;
                    col[j]++;
                }
            }
        }
       // cout<<cont<<endl;
        int total = (v+1)*(h+1);
        int value = cont/total;
        int flag = 0;
        if( cont%total !=  0 )
        {
            flag = 1;
        }

       // cout<<"flag ="<<flag<<endl;
        if( flag == 0)
        {
            flag = solve(value,h,v);
        }
        if( cont == 0)
            flag = 0;
        if( flag == 1)
            printf("Case #%d: IMPOSSIBLE\n",xx);
        else
            printf("Case #%d: POSSIBLE\n",xx);
        xx++;
    }
    return 0;
}


