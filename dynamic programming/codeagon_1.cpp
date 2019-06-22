#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

    string  S;
    map<char,int> M;
    map<char,int> rem;
    int main()
    {
        cin>>S;
        int k;
        scanf("%d",&k);
        for(auto s:S)
            M[(char)s]++;
        for(auto m:M)
        {
            if( m.second < k)
                rem[(char)m.first] = 1;
        }
        for(auto s:S)
        {
            if( rem[(char)s] == 1)
                continue;
            cout<<s;
        }

        return 0;
    }
