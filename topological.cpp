#include <bits/stdc++.h>
using namespace std;

/*
Kahn's Algorithm (BFS on indegrees) for DAGs.
- Removes nodes with indegree 0, decreasing neighbors.
Detects cycle if processed count < n.
Time: O(V+E)
*/

vector<int> topoKahn(int n, const vector<vector<int>>& g){
    vector<int> indeg(n), order;
    for(int u=0;u<n;++u) for(int v:g[u]) indeg[v]++;
    queue<int> q;
    for(int i=0;i<n;++i) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        int u=q.front(); q.pop();
        order.push_back(u);
        for(int v:g[u]) if(--indeg[v]==0) q.push(v);
    }
    if((int)order.size()!=n) return {}; // cycle
    return order;
}

int main(){
    int n=6;
    vector<vector<int>> g = {{}, {2,3}, {4}, {4}, {5}, {}};
    auto order = topoKahn(n, g);
    if(order.empty()) cout<<"Cycle!\n";
    else for(int x:order) cout<<x<<" ";
}
