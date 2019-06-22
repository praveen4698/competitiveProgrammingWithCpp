#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

#define LIMIT 20000000
char buffer[LIMIT], *pos;

long i, j, q, n,Q,l,r,p;
int niz[100005], sol;
int KT2[100005],KT3[100005],KT5[100005];
int minus2[100005],minus3[100005],minus5[100005];

void add2(int x, int kolko) {
  while (x<=n+1) {
    KT2[x]+=kolko;
    x+=(x&(-x));
  }
}
int sum2(int x) {
  int PomSum=0;
  while (x) {
    PomSum+=KT2[x];
    x-=(x&(-x));
  }
  return PomSum;
}
void add3(int x, int kolko) {
  while (x<=n+1) {
    KT3[x]+=kolko;
    x+=(x&(-x));
  }
}
int sum3(int x) {
  int PomSum=0;
  while (x) {
    PomSum+=KT3[x];
    x-=(x&(-x));
  }
  return PomSum;
}
void add5(int x, int kolko) {
  while (x<=n+1) {
    KT5[x]+=kolko;
    x+=(x&(-x));
  }
}
int sum5(int x) {
  int PomSum=0;
  while (x) {
    PomSum+=KT5[x];
    x-=(x&(-x));
  }
  return PomSum;
}
inline int getint() {
  char cc;
  while ((cc=*pos++)<'0');
  int num = cc - '0';
  while ((cc=*pos++)>='0') num = num * 10 + cc - '0';
  return num;
}

void tip2() {
    for (int i=1; i<=q; i++) {
//      scanf("%d", &Q);
      Q=getint();

      if (Q==1) {
          l=getint();
          r=getint();
          p=getint();
//          scanf("%d %d %d", &l, &r, &p);
          if (p==2) {add2(l,1);add2(r+1,-1);}
          else if (p==3) {add3(l,1);add3(r+1,-1);}
               else {add5(l,1);add5(r+1,-1);}
      }
      else {
//          scanf("%d %d", &l, &r);
          l=getint();
          r=getint();
          niz[l]=r;
          minus2[l]=sum2(l);
          minus3[l]=sum3(l);
          minus5[l]=sum5(l);
      }
    }
/*    printf("sa dvojkama deljivost:");
    for (int i=1; i<=n; i++) printf("%d ", sum2(i));
    printf("\n");
    printf("sa trojkama deljivost:");
    for (int i=1; i<=n; i++) printf("%d ", sum3(i));
    printf("\n");
    printf("sa peticama deljivost:");
    for (int i=1; i<=n; i++) printf("%d ", sum5(i));
    printf("\n");
*/
    for (int i=1; i<=n; i++) {
      int times=sum2(i)-minus2[i];
      while (times>0 and niz[i]%2==0) {niz[i]/=2; times--;}
      times=times=sum3(i)-minus3[i];
      while (times>0 and niz[i]%3==0) {niz[i]/=3; times--;}
      times=times=sum5(i)-minus5[i];
      while (times>0 and niz[i]%5==0) {niz[i]/=5; times--;}
    }
}

int main(){
//    freopen("hex.in", "r", stdin);
//    freopen("dule.out", "w", stdout);
    fread(buffer, 1, LIMIT, stdin);
    pos=buffer;
    n=getint();
//    scanf("%d",&n);
    for (int i=1; i<=n; i++) niz[i]=getint();
//    for (int i=1; i<=n; i++) scanf("%d",&niz[i]);

//    scanf("%d",&q);
    q=getint();
//    if (n<=100) tip1();
    tip2();

    for (int j=1; j<=n; j++) printf("%d ", niz[j]);
    return 0;
}
