#include<iostream>
#include<queue>
     using namespace std;
     void showq(queue<int> gq)
     {
     	queue<int> g = gq; 
     	while(!g.empty())
     	{
     		printf("%d ",g.front());
     		g.pop();
		 }
		 printf("\n");
	 }
	 
	 int main()
	 {
	 	queue<int> gq ;
	 	gq.push(10);
	 	gq.push(20);
	 	printf("gq queue is : ");
	 	showq(gq);
	 	printf("gq.size() = %d\n",gq.size());
	 	printf("gq.front() = %d\n",gq.front());
	 	printf("gq.back() = %d\n",gq.back());
	 	printf("gq.pop() : ");
	 	gq.pop();
	 	showq(gq);
	 	return 0;
	 }
