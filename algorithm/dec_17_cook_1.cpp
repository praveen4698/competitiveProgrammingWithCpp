#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define ll long long int
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d %d",&x,&y)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define P(x) printf("%d\n",x)
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    map<string,int> M;
    vector<string> A;
    int t;
    S(t);
    while(t--)
    {
        int n;
        S(n);
        M.clear();
        A.clear();
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            M[s]++;
            if( M[s] == 1)
                A.push_back(s);
        }
        if( A.size() == 1)
        {
            cout<<A[0]<<endl;
        }
        else
        {
            if( M[A[0]] > M[A[1]])
                cout<<A[0]<<endl;
            else if( M[A[0]] < M[A[1]])
                cout<<A[1]<<endl;
            else
                cout<<"Draw"<<endl;
        }


    }
    return 0;

}
