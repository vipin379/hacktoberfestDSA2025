#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class FloydWarshall {
public:
    static const int INF = INT_MAX;
    // Function to implement Floyd Warshall Algorithm
    vector<vector<int>> findAllPairShortestPath(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> dist = graph;

        // Initialize the distance matrix
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(i != j && dist[i][j] == 0) {
                    dist[i][j] = INF;
                }
            }
        }

        // Core Floyd-Warshall algorithm
        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    if(dist[i][k] != INF && dist[k][j] != INF && 
                       dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Check for negative cycles
        for(int i = 0; i < V; i++) {
            if(dist[i][i] < 0) {
                cout << "Graph contains negative weight cycle!" << endl;
                return vector<vector<int>>();
            }
        }

        return dist;
    }

    // Utility function to print the distance matrix
    void printSolution(const vector<vector<int>>& dist) {
        int V = dist.size();
        cout << "Shortest distances between every pair of vertices:\n";
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Driver code
int main() {
    // Example graph representation using adjacency matrix
    vector<vector<int>> graph = {
        {0, 5, FloydWarshall::INF, 10},
        {FloydWarshall::INF, 0, 3, FloydWarshall::INF},
        {FloydWarshall::INF, FloydWarshall::INF, 0, 1},
        {FloydWarshall::INF, FloydWarshall::INF, FloydWarshall::INF, 0}
    };

    FloydWarshall fw;
    vector<vector<int>> result = fw.findAllPairShortestPath(graph);
    
    if(!result.empty()) {
        fw.printSolution(result);
    }

    return 0;
}