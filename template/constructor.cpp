
   #include<iostream>
   #include<stdio.h>
     
      using namespace std;
         
           class Point
           {
           	 private:
           	 	int x ,y;
           	 public:
				Point (int X1, int Y2)
				{
					x = X1;
					y = Y2;
					}
				int Getx()
				{
					return x;
						}	
				int Gety()
				{
					return y;
							}			
		   };
		   
		   int main()
		   {
		   	 Point p(10,15);
		   	 printf("X = %d\n",p.Getx());
		   	 printf("Y = %d\n",p.Gety());
		   	 return  0;
		   	 
		   }
