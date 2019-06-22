#include<iostream>
#include<deque>
#include<iterator>
   
     using namespace std;
     
     void showdq(deque<int> g)
     {
     	deque<int> :: iterator it;
     	for(it = g.begin();it != g.end(); ++it)
     	{
     		printf("%d ",*it);
		 }
		printf("\n"); 
	 }
	 int main()
	 {
	 	deque<int> g;
	 	g.push_back(10);
	 	g.push_front(20);
	 	g.push_back(30);
	 	g.push_front(15);
	 	printf("the deque g is : ");
	 	showdq(g);
	 	return 0;
	 }
