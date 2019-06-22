// count all the divisor upto n


int minp[N];
char deg[N];
short d[N];
int num[D]={0};
int ans[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int i,j;
	for(i=2;(j=i*i)<N;i++) if(!minp[i])
		for(;j<N;j+=i) if(!minp[j]) minp[j]=i;
	d[1]=1;
	deg[1]=1;
	for(i=2;i<N;i++)
	{
		int &p=minp[i];
		if(!p) p=i;
		int j=i/p;
		if(minp[j]!=p)
		{
			deg[i]=2;
			d[i]=deg[j]*d[j];
		}
		else
		{
			deg[i]=deg[j]+1;
			d[i]=d[j];
		}
	}
	ans[0]=1;
	for(i=1;i<N;i++)
		ans[i]=LL(++num[deg[i]*d[i]])*ans[i-1]%MOD;
  // for more search codechef BBSYSTEM



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
