#include <bits/stdc++.h>
using namespace std;
#define LL long long

/*This function is used to find
the sum of digits of all numbers
from 1 to a*/
LL digitSum(LL a)
{
   if(a/10==0)
      return a*(a+1)/2;
   LL n=a;
   LL i=0,p;
   /*After this loop, n
   will have only 1 digit left*/
   while(n/10!=0)
   {
      i++;
      n/=10;
   }
   p=pow(10,i);
   return ((n*45*i*p/10)+(n*(n-1)*p/2)+ n*(a%p+1)+digitSum(a%p));
}

int main() {

   LL a,b;
   cin>>a>>b;
   while(a!=-1)
   {
      cout<<digitSum(b)-digitSum(a-1);
      cout<<"\n";
      cin>>a>>b;
   }
   return 0;
}
