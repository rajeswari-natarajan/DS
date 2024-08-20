// To be checked
# include <iostream>
# include <vector>
# define max 100
using namespace std;
vector <int> adj[10];
bool visited[max];

void dfs(int s) 
{
    visited[s] = true;
    cout<<s<<"-->";
    for(int i = 0;i < adj[s].size();++i)    
	{
    	if(visited[adj[s][i]] == false)
            dfs(adj[s][i]);
   }
}

void initialize() 
{
	
    for(int i = 0;i < 10;++i)
	    visited[i] = false;
}

int main() 
{
	int nodes, edges, x, y;
	cout<<"No. of Vertices \n";
    cin>>nodes;                       //Number of nodes
    cout<<"No. of Edges \n";
    cin>>edges;                       //Number of edges
    for(int i = 0;i < edges;++i) 
	{
		cout<<"Edge "<<i+1<<endl;
	    cin >> x >> y;     
        adj[x].push_back(y);                   //Edge from vertex x to vertex y
        // If the graph is undirected the following line has to be included. Otherwise comment it
        //adj[y].push_back(x);                   //Edge from vertex y to vertex x
    }
    initialize();                           //Initialize all nodes as not visited
    for(int i=1;i<=nodes;++i) 
        if(visited[i] == false)     
            dfs(i);
    return 0;
}

