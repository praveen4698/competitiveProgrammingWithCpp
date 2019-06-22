#include<stdio.h>

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define N_MAX 2229283
#define SQRT_N_MAX 1494
#define DIV_MAX 321
#define MOD 500009

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}
int ps, p[SQRT_N_MAX];

unsigned short num_div[N_MAX], min_div[N_MAX], per[N_MAX];
unsigned char deg[N_MAX];
int sum_num_div[DIV_MAX];
int res[N_MAX];

char buf[100];
int read_int(void){
  int i, res=0;
  gets(buf);
  for(i=0;;i++){
    if(buf[i]<' ') break;
    res = res*10 + (buf[i]-'0');
  }
  return res;
}


int main(){
  int i, j, mi;
  long long k;
  int T, N;

  ps = getPrime(SQRT_N_MAX, p);
  rep(i,ps){
    k = p[i];
    for(j=k;j<N_MAX;j+=k) if(!min_div[j]) min_div[j] = k;
  }

  num_div[1] = per[i] = 1;
  for(i=2;i<N_MAX;i++){
    mi = min_div[i];
    if(!mi) mi = i;
    j = i/mi;
    if(min_div[j] != mi){
      deg[i] = 2;
      per[i] = num_div[j];
      num_div[i] = num_div[j]*2;
    } else {
      deg[i] = deg[j] + 1;
      per[i] = per[j];
      num_div[i] = per[j] * deg[i];
    }
  }

  res[0] = res[1] = 1;
  for(i=2;i<N_MAX;i++){
    k = ++sum_num_div[num_div[i]];
    res[i] = (res[i-1] * k) % MOD;
  }
 // rep(i,100) printf("%d %d\n",i,sum_num_div[i]);

  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    if(N >= N_MAX) printf("%d\n",MOD-1);
    else           printf("%d\n",res[N]-1);
  }

  return 0;
}
