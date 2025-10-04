#include <bits/stdc++.h>
using namespace std;

/*
🧠 Depth First Search (DFS)
- Explores as far as possible before backtracking.
- Uses recursion or stack.
- Time Complexity: O(V + E)
*/

void dfsHelper(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

void dfs(int start, vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    dfsHelper(start, adj, visited);
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    cout << "DFS Traversal: ";
    dfs(0, adj);
}
