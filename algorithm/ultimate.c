#include<stdio.h>
#include<math.h>
#include<complex.h>
    
    
	
	int FFT(double complex A[101],int n,double complex omega,double complex B[101])
	{
		//int n = end - start;
		if(n == 1)
		{
			B[n-1] = A[n-1];
			return 0;
		}
		//printf("%d\n",n);	 
		double complex C[101],D[101],E[101],F[101];
		double complex u = 1;
		int k;
		for(k=0;k< n/2;++k)
		{
			C[k] = A[k] + A[k+ n/2 ];
			D[k] = u*(A[k] - A[k + n/2 ]);
			u = u*omega;
		}
		
		FFT(C,n/2,omega*omega,E);
		FFT(D,n/2,omega*omega,F);
		
		for(k=0;k<n/2;++k)
		{
			B[2*k] = E[k];
			B[2*k + 1] = F[k];
		}
		
				
	}

	int main()
	{
		int  A1[101];
		double complex A[101];
		double complex B[101];
		int n;
		printf("enter the value of n: ");
		scanf("%d",&n);
		printf("enter the array: ");
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&A1[i]);
			A[i] = A1[i];
			
		}
		for(i=0;i<n;++i)
		{
			printf("%g + %gi\n",creal(A[i]),cimag(A[i]));
		}
		float pi = atan2(1,1)*4;
		printf("%f\n",pi);
		double complex omega = cexp(-I*pi*2/n);
		printf("%g + %gi\n",creal(omega),cimag(omega)); 
		FFT(A,n,omega,B);
		printf("finally ::\n");
		for(i=0;i<n;++i)
		{
			printf("%g   +    %gi\n",creal(B[i]),cimag(B[i]));
		}
		
		return 0;
		
	}
