#include<iostream>
#include<queue>
  
     using namespace std;
      
         void showpq(priority_queue<int> gq)
         {
         	priority_queue<int> g = gq; 
         	while(!g.empty())
         	{
         		printf("%d ",g.top());
         		g.pop();
			 }
			 printf("\n");
		 }
		 int main()
		 {
		 	priority_queue<int> gq;
		 	gq.push(10);
		 	gq.push(30);
		 	gq.push(20);
		 	gq.push(5);
		 	gq.push(7);
		 	printf("the given priority queue is : ");
		 	showpq(gq);
		 	printf("gq.size() = %d\n",gq.size());
		 	printf("gq.top() = %d\n",gq.top());
		 	printf("gq.pop() = ");
		 	gq.pop();
		 	showpq(gq);
		 	
		 	return 0;
		 }
