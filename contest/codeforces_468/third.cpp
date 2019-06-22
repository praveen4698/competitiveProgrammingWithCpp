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

const int lim = 1e5+10;
vector<int> A;
int main()
{
    int n;
    scan(n);
    for(int i=0;i<n;++i)
    {
        int a;
        scan(a);
        A.pb(a);
    }
    sort(all(A));
    int maxi = -INF;
    int mini = INF;
    for(int i=0;i<n;++i)
    {
        mini = min(mini,A[i]);
        maxi = max(maxi,A[i]);
    }
    if( maxi - mini == 2)
    {
        int a = 0,b = 0,c = 0;
        for(int i=0;i<n;++i)
        {
            if( A[i] == mini)
                a++;
            else if( A[i] == maxi)
                c++;
            else
                b++;
        }
        int ans1 = n;
        vector<int> ansa;
        if( a < c)
        {
            ans1 = ans1 - 2*a;
            ansa.pb(0);
            ansa.pb(b+2*a);
            ansa.pb(c-a);

        }
        else
        {
            ans1 = ans1 - 2*c;
            ansa.pb(a-c);
            ansa.pb(b+2*c);
            ansa.pb(0);
        }
        int ans2 = n;
        int mm = b/2;
        a = a + mm;
        c = c + mm;
        b = b - 2*mm;
        ans2 = ans2 - 2*mm;
        if( ans1 < ans2)
        {
            cout<<ans1<<endl;
            for(int i=0;i<ansa[0];++i)
                cout<<mini<<" ";
            for(int i=0;i<ansa[1];++i)
                cout<<mini+1<<" ";
            for(int i=0;i<ansa[2];++i)
                cout<<maxi<<" ";
        }
        else
        {
            cout<<ans2<<endl;
            for(int i=0;i<a;++i)
                cout<<mini<<" ";
            for(int i=0;i<b;++i)
                cout<<mini+1<<" ";
            for(int i=0;i<c;++i)
                cout<<maxi<<" ";
        }
    }
    else
    {
        cout<<n<<endl;
        for(int a: A)
            cout<<a<<" ";
    }

    return 0;
}


