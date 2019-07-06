#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;


    int main()
    {
        int x1,x2,x3,y1,y2,y3;
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        int dis1 = (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
        int dis2 = (y3-y2)*(y3-y2) + (x3-x2)*(x3-x2);
        int dis3 = (y3-y1)*(y3-y1) + (x3-x1)*(x3-x1);
        //printf("%d %d %d")
        int area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
        if( dis1 == dis2 && area != 0 )
            printf("yes");
        else
            printf("no");
        return 0;
    }
