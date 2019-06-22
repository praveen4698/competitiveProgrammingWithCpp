#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    vector<int> leap,nonleap;
    leap.push_back(31);
    leap.push_back(29);
    leap.push_back(31);
    leap.push_back(30);
    leap.push_back(31);
    leap.push_back(30);
    leap.push_back(31);
    leap.push_back(31);
    leap.push_back(30);
    leap.push_back(31);
    leap.push_back(30);
    leap.push_back(31);
    nonleap.push_back(31);
    nonleap.push_back(28);
    nonleap.push_back(31);
    nonleap.push_back(30);
    nonleap.push_back(31);
    nonleap.push_back(30);
    nonleap.push_back(31);
    nonleap.push_back(31);
    nonleap.push_back(30);
    nonleap.push_back(31);
    nonleap.push_back(30);
    nonleap.push_back(31);
    vector<int> ans1,ans2,ans3,ans;
    for(int i=0;i<3;++i)
    {
        for(auto a:nonleap)
            ans.push_back(a);
        if( i == 0)
        {
            for(auto a:leap)
                ans1.push_back(a);
        }
        else
        {
            for(auto a:nonleap)
                ans1.push_back(a);
        }
        if( i == 1)
        {
            for(auto a:leap)
                ans2.push_back(a);
        }
        else
        {
            for(auto a:nonleap)
                ans2.push_back(a);
        }
        if( i == 2)
        {
            for(auto a:leap)
                ans3.push_back(a);
        }
        else
        {
            for(auto a:nonleap)
                ans3.push_back(a);
        }
    }
    int n;
    scanf("%d",&n);
    vector<int> A;
    for(int i=0;i<n;++i)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<ans.size()-n;++i)
    {
        int cont = 0;
        for(int j=0;j<n;++j)
        {
            if( ans[i+j] == A[j])
                cont++;
        }
        if( cont == n)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=0;i<ans1.size()-n;++i)
    {
        int cont = 0;
        for(int j=0;j<n;++j)
        {
            if( ans1[i+j] == A[j])
                cont++;
        }
        if( cont == n)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=0;i<ans2.size()-n;++i)
    {
        int cont = 0;
        for(int j=0;j<n;++j)
        {
            if( ans2[i+j] == A[j])
                cont++;
        }
        if( cont == n)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=0;i<ans3.size()-n;++i)
    {
        int cont = 0;
        for(int j=0;j<n;++j)
        {
            if( ans3[i+j] == A[j])
                cont++;
        }
        if( cont == n)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
