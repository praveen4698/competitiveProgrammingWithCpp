#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<pair<int,int> > vpii;
static const int INF = 0x3f3f3f3f;
static const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

struct Treap
{
    int value,priority,sz;
    Treap *left,*right;
    Treap(): sz(0),value(0),priority(0),left(NULL),right(NULL){};
    Treap(int x,int y)
    {
        value = x;
        priority = y;
        sz = 1;
        left = NULL;
        right = NULL;
    }
};
typedef Treap* pTreap;
int Tsize(pTreap t)
{
        return t?t->sz:0;
}
int update_size(pTreap t)
{
    if( t != NULL)
        t->sz = Tsize(t->left)+1+Tsize(t->right);
}
void split(pTreap t,pTreap &l, pTreap &r,int key)
{
    if( t == NULL)
        l = r = NULL;
    else if( t->value <= key)
    {
        split(t->right,t->right,r,key);
        l = t;
    }
    else
    {
        split(t->left,l,t->left,key);
        r = t;
    }
    update_size(t);

}
void Merge(pTreap &t,pTreap l,pTreap r)
{
    if( l == NULL || r == NULL)
        t = (l!=NULL)?l:r;
    else if( l->priority > r->priority)
    {
        Merge(l->right,l->right,r);
        t = l;
    }
    else
    {
        Merge(r->left,l,r->left);
        t = r;
    }
    update_size(t);
}
void Insert(pTreap &t,pTreap it)
{
    if( t == NULL)
        t = it;
    else if( it->priority > t->priority)
    {
        split(t,it->left,it->right,it->value);
        t = it;
    }
    else
    {
        Insert(t->value<=it->value?t->right:t->left,it);
    }
    update_size(t);
}
void Erase(pTreap &t,int key)
{
    if( t == NULL)
        return ;
    else if( t->value == key)
    {
        pTreap temp = t;
        Merge(t,t->left,t->right);
        free(temp);
    }
    else
    {
        Erase(t->value<key?t->right:t->left,key);

    }
    update_size(t);
}
pTreap  head = NULL;
int main()
{
    int x;
    cin>>x;
    pTreap temp = new Treap(x,rand());
    return 0;
}
