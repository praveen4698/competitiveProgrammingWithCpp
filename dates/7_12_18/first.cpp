//not mine 
#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define pi pair<int,int>
int n,c1,c2,num,du[maxn];
vector<int>one,two;
vector<pi>g;
int lop[maxn],sz;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        if(x==1) {++c1;one.push_back(i);}
        else {num++;c2+=x;two.push_back(i);}
        du[i]=x;
    }
    if(c1==n) return 0*printf("NO\n");
    int lx=0;
    if(num==1) lx=c2;
    else lx=c2-2*num+2;
    if(lx<c1) return 0*printf("NO\n");
    printf("YES %d\n",min(c1,2)+num-1);
    if(!one.empty())
    {
        lop[sz++]=one.back();
        one.pop_back();
    }
    for(auto v:two)
        lop[sz++]=v;
    if(!one.empty())
    {
        lop[sz++]=one.back();
        one.pop_back();
    }
    for(int i=0;i<sz;++i)
        if(i==0||i==sz-1) du[lop[i]]--;
        else du[lop[i]]-=2;
    for(int i=0;i<sz-1;++i) g.push_back(pi(lop[i],lop[i+1]));
    int pt=0;
    while(!one.empty())
    {
        int u=one.back();
        one.pop_back();
        while(du[lop[pt]]==0) pt++;
        du[lop[pt]]--;
        g.push_back(pi(u,lop[pt]));
    }
    printf("%d\n",(int)g.size());
    for(auto it:g)
        printf("%d %d\n",it.first,it.second);
    return 0;
}