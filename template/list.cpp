#include<iostream>
#include<list>
#include<iterator>
   
     using namespace std;
      
        void showlist( list<int> g)
        {
        	list<int> :: iterator it;
        	for(it = g.begin();it != g.end();++it)
        	{
        		printf("%d ",*it);
			}
			printf("\n");
		}
		
		int main()
		{
			list<int> gq1,gq2;
			
			for(int i = 0;i < 10 ; i++)
			{
				gq1.push_back(i*2);
				gq2.push_front(i*3);
			}
			
			printf("list1 is : ");
			showlist(gq1);
			printf("list2 is : ");
			showlist(gq2);
			printf("gq1.front() : %d\n",gq1.front());
			printf("gq1.back() : %d\n",gq1.back());
			printf("gq1.pop_front() : ");
			gq1.pop_front();
			showlist(gq1);
			printf("gq2.pop_back() : ");
			gq2.pop_back();
			showlist(gq2);
			printf("gq.reverse() : ");
			gq1.reverse();
			showlist(gq1);
			printf("gq2.sort : ");
			gq2.sort();
			showlist(gq2);
			return 0;
		}
