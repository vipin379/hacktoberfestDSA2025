#include <bits/stdc++.h>
using namespace std;

/*
🧠 Dijkstra’s Algorithm
- Finds shortest path from source to all vertices in a weighted graph.
- Uses a min-priority queue.
- Time Complexity: O((V + E) log V)
*/

void dijkstra(int start, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    // min-heap: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " -> " << dist[i] << "\n";
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    // undirected weighted graph
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    dijkstra(0, adj);
}
