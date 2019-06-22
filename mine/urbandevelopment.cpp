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
            for(;i>=0;i=i = (i & (i + 1)) - 1)
            {
                res+=f[i];
            }
            return res;
        }
    };
    struct Line
    {
        int x1,y1,x2,y2;
        int answer;
        int idx;

        Line(int x1__,int y1__,int x2__,int y2__,int indx)
        :x1(x1__),y1(y1__),x2(x2__),y2(y2__),answer(0),idx(indx)
        {
            if( isvertical() )
                if( y1 > y2) swap(y1,y2);
            else if( ishorizontal() )
                if( x1 > y2 ) swap(x1,x2);
        }
        bool isvertical() const
        {
            return x1==x2;
        }
        bool ishorizontal() const
        {
            return y1==y2;
        }
    };
    void solve(vector<Line> &horizontal,vector<Line> &vertical )
    {
        vector< pair< pair<int ,int > ,Line* > > events;
        vector< pair< int ,int > > endpoints;
        endpoints.reserve(horizontal.size()*2);

        for(Line& line: horizontal)
        {
            events.emplace_back(make_pair(line.x1,-1),&line);
            events.emplace_back(make_pair(line.x2,1),&line);
            endpoints.push_back(make_pair(line.x1,line.y1));
            endpoints.push_back(make_pair(line.x2,line.y2));
        }
        for(Line &line : vertical)
        {
            events.emplace_back(make_pair(line.x1,0),&line);
        }
        sort(endpoints.begin(),endpoints.end());

        auto cont = [&endpoints](int x,int y)
        {
            auto it = lower_bound(endpoints.begin(),endpoints.end(),make_pair(x,y));
            int v  = (int)(it != endpoints.end() && *it == make_pair(x,y));
            return v;
        };
        fenwick f(100010);
        sort(events.begin(),events.end());
        for(auto& event : events)
        {
            int type = event.first.second;
            Line &line = *event.second;
            if(type == -1 )
            {
                f.update(line.y1,+1);
            }
            else if( type == 0)
            {
                line.answer = f.get(line.y2) - f.get(line.y1 - 1);
                line.answer-=cont(line.x1,line.y1);
                line.answer-=cont(line.x2,line.y2);
            }
            else if( type == 1)
            {
                f.update(line.y2,-1);
            }
        }

    }

    int main()
    {

            int n;
            scanf("%d",&n);
            vector<Line> horizontal;
            vector<Line> vertical;
            for(int i=0;i<n;++i)
            {
                int x1,x2,y1,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                Line line(x1,y1,x2,y2,i);
                if( line.ishorizontal())
                    horizontal.push_back(line);
                else
                    vertical.push_back(line);
            }
            solve(horizontal,vertical);
            for (Line& line : horizontal)
            {
                swap(line.x1, line.y1);
                swap(line.x2, line.y2);
            }
            for (Line& line : vertical)
            {
                swap(line.x1, line.y1);
                swap(line.x2, line.y2);
            }

            solve(vertical, horizontal);

            vector<int> ans(n);
            for (Line& line : horizontal) ans[line.idx] = line.answer;
            for (Line& line : vertical) ans[line.idx] = line.answer;

            long long int sum = 0;
            for (int i = 0; i < ans.size(); ++i)
            {
                sum += ans[i];
            }

            cout << sum / 2 << endl;
            for (int i = 0; i < ans.size(); ++i)
            {
                printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
            }

        return 0;
    }
