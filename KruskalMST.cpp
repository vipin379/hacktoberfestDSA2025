/*
 * KruskalMST.cpp
 *
 * Problem:
 * Given a connected, weighted, undirected graph — find its Minimum Spanning Tree (MST)
 * using Kruskal’s Algorithm (Greedy approach + DSU).
 *
 * Time Complexity: O(E log E)
 * Space Complexity: O(V)
 */

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
};

int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    DSU dsu(V);
    int mstWeight = 0;
    vector<vector<int>> mst;

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            mstWeight += w;
            mst.push_back(e);
        }
    }

    cout << "Edges in MST:\n";
    for (auto &e : mst)
        cout << e[0] << " - " << e[1] << " (weight " << e[2] << ")\n";
    cout << "Total weight: " << mstWeight << endl;

    return 0;
}
