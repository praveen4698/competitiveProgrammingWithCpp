#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
    using namespace std;
    class Graph
	{
    	int V;
    	vector<pair<int ,int > > *adj;
    	vector<int> *temp;
    	bool *leaf;
    	public:
    		Graph(int V);
    		void addedge(int u ,int v);
    		void Dijkstra(int m,int A[100001]);
    		
	};
	
	Graph::Graph(int V)
	{
		this->V = V;
		adj = new vector<pair<int,int > > [V];
		temp = new vector<int> [V];
		leaf = new bool [V];
		for(int i = 0;i<V;++i)
		{
			leaf[i] = true;
		}
	}
	void Graph::addedge(int u,int v)
	{
		temp[u].push_back(v);
		temp[v].push_back(u);
		
	}
	void Graph::Dijkstra(int m,int A[100001])
	{
	    
	    bool *visited = new bool[V];
	    for(int i = 0;i<V;++i)
	    {
	    	visited[i] = false;
		}
		queue<int> q ;
		vector<int>::iterator j;
		q.push(1);
		visited[1] = true;
		while(!q.empty())
		{
			int t = q.front();
			q.pop();
			for(j = temp[t].begin();j != temp[t].end();++j)
			{
				
				if(!visited[*j])
				{
					q.push(*j);
					adj[t].push_back(make_pair((*j),A[t]));
					visited[*j] = true;
					leaf[t] = false;
				}
			}
		}
	
	    leaf[1] =false;
		queue<pair<int ,int> > Q;
		Q.push(make_pair(1,0));
	    vector<pair<int,int> >::iterator i;
	    int count = 0;
		while(!Q.empty())
		{
			pair<int ,int > t = Q.front();
			Q.pop();
			int u = t.first;
			int v = t.second;
			visited[u] = true;
			if( leaf[u] == true)
			{
				if( v + A[u] <= m)
	           {
					count = count + 1;
				}
			}
			else 
			{
				for(i = adj[u].begin();i != adj[u].end();++i)
				{
			
				if( v > m)
				{
				      Q.push(make_pair((*i).first,v+1));     	
				}
				else if((*i).second == 1)
				{   
				    
					Q.push(make_pair((*i).first,(*i).second + v));
				}
				else
				{
					Q.push(make_pair((*i).first,0));
				}
			    }
			}
			
			
			
		}
		printf("%d",count);
	}
	int main()
	{
		int n;
		int A[100001];
		int m;
		scanf("%d %d",&n,&m);
		Graph g(n+1);
		for(int i=1;i<n+1;++i)
		{
			scanf("%d",&A[i]);
		}
		
		for(int i=1;i<n;++i)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			g.addedge(a,b);
		}
		g.Dijkstra(m,A);
		return 0;
	}
