#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    const int lim = 1e5+10;
    int n,k,m;
    struct comp
    {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
            {return lhs.first<rhs.first;}
    };
    vector<int> Q;

    pair<int,int> func(vector<pair<int,int > > &X)
    {
            Q.clear();
            int lo = ((n-k)/2) +1;
            int hi = lo + k -1;
            int flag = 0;
            int cont = 0;
            int prev = lo;

            for(int i=0;i<m;++i)
            {

                if(X[i].second >= lo && X[i].first <= hi)
                {
                    if(X[i].first <= prev && X[i].second >= prev)
                    {
                        prev =  X[i].second + 1;
                        cont++;
                        if(Q.empty() == true)
                        {
                            Q.push_back((X[i].second)+1);
                        }
                        else if( Q.front() >= X[i].first)
                        {
                            int temp = Q.size();
                            cont = cont - temp+1;
                            temp = Q.front();
                            Q.clear();
                            Q.push_back(temp);
                            Q.push_back((X[i].second)+1);
                        }
                        else if( Q.front() < X[i].first)
                        {
                            while(Q.front() < X[i].first && Q.empty() == false)
                            {
                                Q.erase(Q.begin());
                            }
                            Q.push_back((X[i].second)+1);
                        }
                    }

                }
                if( prev > hi)
                {
                    i = n+1;
                    break;
                }
               // printf("lo =%d hi= %d prev= %d cont= %d\n",X[i].first,X[i].second,prev,cont);


            }
            if( prev <= hi)
                flag = 1;
            return make_pair(flag,cont);
    }
    vector<pair<int,int> > X,Y;
    int main()
    {
        int t;
        scanf("%d",&t);

        while(t--)
        {
            X.clear();
            Y.clear();
            scanf("%d %d %d",&n,&k,&m);
            for(int i=0;i<m;++i)
            {
                int x1,y1,x2,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                X.push_back(make_pair(min(x1,x2),max(x1,x2)));
                Y.push_back(make_pair(min(y1,y2),max(y1,y2)));
            }
            sort(X.begin(),X.end(),comp());
            sort(Y.begin(),Y.end(),comp());
           // for(int i=0;i<m;++i)
           // {

              //  printf("%d %d\n",X[i].first,X[i].second);
          //  }
            pair<int,int > ans1 = func(X);
            pair<int,int> ans2 = func(Y);
            if( ans1.first == 0 && ans2.first == 0)
                printf("%d\n",ans1.second+ans2.second);
            else
                printf("-1\n");

        }
        return 0;
    }
