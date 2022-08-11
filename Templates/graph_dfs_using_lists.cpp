//Jai Shree Ram
// Directed graph BFS
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void addEdge(list<int> *adj, int u, int v)
{
    adj[u].push_back(v);
}
void dfs(list<int> *adj, int start_node, int no_of_nodes)
{
    bool *visited = new bool[no_of_nodes];
    for(int i=0; i<no_of_nodes; i++)
    {   
        visited[i] = false;
    }
    stack<int> st;
    visited[start_node] = true;
    st.push(start_node);
    while (!st.empty())
    {
        start_node = st.top();
        cout<<start_node<<" ";
        st.pop();
        for(auto i = adj[start_node].begin(); i != adj[start_node].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                st.push(*i);
            }
        }
    }
}
void solve()
{
    list<int> *adj = new list<int>[10];
    addEdge(adj, 0, 9);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 9, 3);
    dfs(adj, 2, 10);
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