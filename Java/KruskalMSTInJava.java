import java.util.*;

// Class to represent an edge in a graph
class Edge implements Comparable<Edge> {
    int source, destination, weight;

    public Edge(int source, int destination, int weight) {
        this.source = source;
        this.destination = destination;
        this.weight = weight;
    }

    // Compare edges by weight for sorting
    public int compareTo(Edge compareEdge) {
        return this.weight - compareEdge.weight;
    }
}

public class KruskalMST {

    // Find set of an element i (with path compression)
    private int findParent(int[] parent, int i) {
        if (parent[i] == -1)
            return i;
        parent[i] = findParent(parent, parent[i]);
        return parent[i];
    }

    // Union of two sets x and y
    private void union(int[] parent, int x, int y) {
        int xSet = findParent(parent, x);
        int ySet = findParent(parent, y);
        parent[xSet] = ySet;
    }

    // Kruskal's MST algorithm
    public List<Edge> findMST(List<Edge> edges, int numberOfVertices) {
        List<Edge> result = new ArrayList<>();
        int[] parent = new int[numberOfVertices];
        Arrays.fill(parent, -1);

        // Sort edges by weight
        Collections.sort(edges);
        int edgesUsed = 0;
        int index = 0;

        // Add edges until MST is complete (V-1 edges)
        while (edgesUsed < numberOfVertices - 1 && index < edges.size()) {
            Edge nextEdge = edges.get(index++);
            int x = findParent(parent, nextEdge.source);
            int y = findParent(parent, nextEdge.destination);

            // If no cycle formed, include edge in MST
            if (x != y) {
                result.add(nextEdge);
                union(parent, x, y);
                edgesUsed++;
            }
        }
        return result;
    }

    // Main method to test the MST implementation
    public static void main(String[] args) {
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(0, 1, 2));
        edges.add(new Edge(0, 3, 6));
        edges.add(new Edge(1, 2, 3));
        edges.add(new Edge(1, 3, 8));
        edges.add(new Edge(1, 4, 5));
        edges.add(new Edge(2, 4, 7));
        edges.add(new Edge(3, 4, 9));

        int numberOfVertices = 5;
        KruskalMST kruskal = new KruskalMST();
        List<Edge> mstEdges = kruskal.findMST(edges, numberOfVertices);

        System.out.println("Edges in Minimum Spanning Tree:");
        int minimumCost = 0;
        for (Edge edge : mstEdges) {
            System.out.println(edge.source + " -- " + edge.destination + " == " + edge.weight);
            minimumCost += edge.weight;
        }
        System.out.println("Total cost of MST: " + minimumCost);
    }
}
