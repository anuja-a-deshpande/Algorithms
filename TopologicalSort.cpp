//Topological sort
// John has n tasks to do. Unfortunately, the tasks are not independent and the execution of one task is
// only possible if other tasks have already been executed.
// Input
    // The input will consist of several instances of the problem. Each instance begins with a line containing
    // two integers, 1 ≤ n ≤ 100 and m. n is the number of tasks (numbered from 1 to n) and m is the
    // number of direct precedence relations between tasks. After this, there will be m lines with two integers
    // i and j, representing the fact that task i must be executed before task j.
    // An instance with n = m = 0 will finish the input.
// Output
    // For each instance, print a line with n integers representing the tasks in a possible order of execution.
// Sample Input
    // 5 4
    // 1 2
    // 2 3
    // 1 3
    // 1 5
    // 0 0
// Sample Output
    // 1 4 2 5 3

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    private:
        /* data */
        int v; // no of vertices

        vector<int>* adj;

    public:
        Graph(int n);
        ~Graph();
       void addEdge(int v, int w);
       void print();
       vector<int> topologicalSort(vector<bool> visited);
       void dfs(int v, vector<bool>& visited, vector<int> &ans);
    };

Graph::Graph(int n)
{
    v = n;
    adj = new vector<int>[v];

}
Graph::~Graph()
{
}
void Graph::addEdge(int n, int w)
{
    adj[n].push_back(w);//push_back[w];
}
void Graph::print()
{
     for (int i = 0; i < 5; i++)
    {
        cout<<i<<" : "<<adj[i].size()<<"\n";
    }
    
}
vector<int> Graph::topologicalSort(vector<bool> visited){

     cout<<"Topo;ogical sort"<<"\n";
    visited.assign(v, false);
    vector<int> ans;
    for (int i = 0; i < v; ++i) {
        if (!visited[i])
            dfs(i, visited, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void Graph::dfs(int v, vector<bool>& visited, vector<int>& ans) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, visited, ans);
    }
    ans.push_back(v);
}

int main()
{
    
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

   
    // g.print();
    vector<bool> visited;
    vector<int> ans = g.topologicalSort(visited);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
