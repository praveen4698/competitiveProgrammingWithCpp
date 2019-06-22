#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const int lim = 2e5+10;
int costperfect[lim],costnon[lim];
vector<pair<int,int> > nonperfect,perfect;
vector<int> square;
vector<int> A;
struct comp1 {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
            {return (lhs.first<rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second));}
        };
struct comp2
 {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
            {return (lhs.second<rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first));}
        };
int main()
{
    for(int i=0;i*i<=1e9;++i)
    {
        square.push_back(i*i);
    }
    int n;

    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int a;
        scanf("%d",&a);
       // A.push_back(a);
        if( a == 0)
        {
            costnon[i] = 2;
            costperfect[i] = 0;
            continue;
        }
        int b = (int)pow(a+0.10000,0.500000);
        if( b*b == a)
        {
            costnon[i] = 1;
            costperfect[i] = 0;

        }
        else
        {
            costnon[i] = 0;
            costperfect[i] = min((b+1)*(b+1)-a,a-(b)*(b));
        }


    }
    for(int i=0;i<n;++i)
    {
        if(costnon[i] > costperfect[i])
        {
            perfect.push_back({costnon[i],costperfect[i]});
        }
        else
        {
            nonperfect.push_back({costnon[i],costperfect[i]});
        }
    }
    sort(perfect.begin(),perfect.end(),comp1());
    sort(nonperfect.begin(),nonperfect.end(),comp2());
    if( perfect.size() > nonperfect.size())
    {
        while(perfect.size() > nonperfect.size())
        {

            nonperfect.push_back({perfect[0].first,perfect[0].second});
            perfect.erase(perfect.begin());
        }

    }
    else if( perfect.size() < nonperfect.size())
    {
         while(perfect.size() < nonperfect.size())
        {

            perfect.push_back({nonperfect[0].first,nonperfect[0].second});
            nonperfect.erase(nonperfect.begin());
        }
    }
    ll cost = 0;
    for(auto a:perfect)
    {
        cost = cost + 1ll*a.second;
    }
    for(auto a:nonperfect)
    {
        cost = cost + 1ll*a.first;
    }
    cout<<cost;
    return 0;
}
