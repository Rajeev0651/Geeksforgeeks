//Jai Shree Ram
// Directed graph BFS
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void addEdge(list<int> *adj,int u, int v)
{
    adj[u].push_back(v);
}
void bfs(list<int> *adj, int start_node, int no_of_nodes)
{
    bool *visited = new bool[no_of_nodes];
    for(int i=0; i<no_of_nodes; i++)
    {   
        visited[i] = false;
    }
    queue<int> qu;
    visited[start_node] = true;
    qu.push(start_node);
    while (!qu.empty())
    {
        start_node = qu.front();
        cout<<start_node<<" ";
        qu.pop();
        for(auto i = adj[start_node].begin(); i != adj[start_node].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                qu.push(*i);
            }
        }
    }
}
void solve()
{
    list<int> *adj = new list<int>[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);
    bfs(adj, 2, 4);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int T;
   cin >> T;
   while (T--)
   {
     solve();
   }
   return 0;
}