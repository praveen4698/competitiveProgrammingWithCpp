#include<bits/stdc++.h>
using namespace std;
#define lp(i,n1,n2) for(int (i)=(int)(n1);(i)<(int)(n2);++(i))
#define lpr(i,n1,n2) for(int (i) =(int)(n1); (i) >= (int)(n2);--(i))
#define scan(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI 3.14159265
#define mod 1000000007
typedef map<int,int> mii;
typedef map<string,string> mss;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef long long ll;
static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
    long long int store[300001],sum[300001],lps[300001];
    char pattern[300001],text[300001];
    void LPS_array(long long int M)
	{
		long long int len = 0;
		long long int i = 1;
		lps[0] =0;

		while(i<M)
		{
			if(pattern[i] == pattern[len])
			{
				len++;
				lps[i] = (long long int)len;
				i++;
			}

			else
			{
				if(len != 0)
				{
					len = lps[len -1]; //most important step
				}
				else
				{
					lps[i] = (long long int )0;
					i++;
				}
			}
		}
	}
	int KMP_algo()
	{
		long long int M = strlen(pattern);
		long long int N = strlen(text);


		long long int j= 0;

		LPS_array(M);

		long long int i = 0;

		while(i<N)
		{
			if(pattern[j] == text[i])
			{
				j++;
				i++;
			}

			if(j == M)
			{
				//printf("found the pattern at %d \n",i-j);
				store[i-j] = (long long int )1;
				j = lps[j-1];
			}

			else if(i<N && pattern[j] != text[i])
			{
				if(j != 0)
				 j = lps[j-1];
				else
				 i = i+1;
			}
		}


	}

    int main()
    {
        int Z;
        scan(Z);
        while(Z--)
        {

            scanf("%s",text);
            scanf("%s",pattern);
            int l = strlen(pattern);
            int n = strlen(text);
            lp(i,0,n+1)
            {
                store[i] = (long long int)0;
                sum[i] = (long long int )0;
                lps[i] = (long long int )0;

            }
            KMP_algo();
           // lp(i,0,n)
            //    printf("store[%d] = %d\n",i,store[i]);

            sum[n-1] = store[n-1];
            lpr(i,n-2,0)
            {
                sum[i] = (long long int)sum[i+1] + store[i];
                sum[i] = sum[i]%mod;
                if( i + l < n)
                    sum[i] = sum[i] + store[i]*sum[i+l];

                sum[i] = sum[i]%mod;
            }
            printf("%lld\n",sum[0]);
        }

        return 0;
    }
