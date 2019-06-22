#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {

        return 0;
    }
                string temp;
                getline( cin , temp );
                stringstream ss( temp );
                int x , y;
                int j = 0;
                while ( ss >> x && ss >> y )
                {

                    A[ x ][ y ] = i ;
                    if( j == 0)
                    {
                        Q[i].push(mp(x,y));
                        j++;
                    }
                }

                struct compare{
        bool operator()(const pair<int,int> l,const pair<int,int> r)
			{
				return l.S > r.S;
			}


		};

		struct comp {
        bool operator() (const pair<int,int>& lhs, const pair<int,int> & rhs) const
            {return lhs.second<rhs.second;}
        };//increasing
        // but reverse in priority_queue;
