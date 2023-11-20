#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

class Graph {
private:
    map<int, vector<pair<int, int>>> edges;

public:
    void addEdge(int from, int to, int weight) {
        if (edges.find(from) == edges.end()) {
            edges[from] = vector<pair<int, int>>();
        }
        edges[from].push_back(make_pair(to, weight));

        if (edges.find(to) == edges.end()) {
            edges[to] = vector<pair<int, int>>();
        }
        edges[to].push_back(make_pair(from, weight));
    }

    void printGraph() {
        for (const auto &entry : edges) {
            int from = entry.first;
            const vector<pair<int, int>>& neighbors = entry.second;

            cout << "Vertex " << from << " is connected to:\n";

            for (const auto& neighbor : neighbors) {
                int to = neighbor.first;
                int weight = neighbor.second;
                cout << "  Vertex " << to << " with weight " << weight << '\n';
            }
        }
    }

    vector<int> BFS(int start) {
        vector<int> result;
        queue<int> queue;
        map<int, bool> visited;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            result.push_back(current);
            for (const auto& neighbor : edges[current]) {
                int to = neighbor.first;
                if (!visited[to]) {
                    visited[to] = true;
                    queue.push(to);
                }
            }
        }

        return result;
    }

    vector<int> DFSUtil(int v, map<int, bool>& visited, vector<int>& result) {
        visited[v] = true;
        result.push_back(v);

        for (const auto& neighbor : edges[v]) {
            int to = neighbor.first;
            if (!visited[to]) {
                DFSUtil(to, visited, result);
            }
        }

        return result;
    }

    vector<int> DFS(int startVertex) {
        map<int, bool> visited;
        vector<int> result;

        return DFSUtil(startVertex, visited, result);
    }

    map<int, int> Dijkstra(int startVertex) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, int> distance;

        for (const auto& entry : edges) {
            int vertex = entry.first;
            distance[vertex] = numeric_limits<int>::max();
        }

        distance[startVertex] = 0;
        pq.push({0, startVertex});

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            pq.pop();

            for (const auto& neighbor : edges[currentVertex]) {
                int to = neighbor.first;
                int weight = neighbor.second;

                if (distance[currentVertex] + weight < distance[to]) {
                    distance[to] = distance[currentVertex] + weight;
                    pq.push({distance[to], to});
                }
            }
        }

        return distance;
    }

    vector<pair<pair<int, int>, int>> Prims(int startVertex) {
        vector<pair<pair<int, int>, int>> pairsDistances;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, bool> visited;

        visited[startVertex] = true;

        for (const auto& neighbor : edges[startVertex]) {
            pq.push({neighbor.second, neighbor.first});
        }

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentWeight = pq.top().first;
            pq.pop();

            // If the current vertex is not visited, add it to the MST
            if (!visited[currentVertex]) {
                pairsDistances.push_back({{startVertex, currentVertex}, currentWeight});
                visited[currentVertex] = true;

                // Add all edges from the current vertex to the priority queue
                for (const auto& neighbor : edges[currentVertex]) {
                    if (!visited[neighbor.first]) {
                        pq.push({neighbor.second, neighbor.first});
                    }
                }
            }
        }
        return pairsDistances;
    }

    vector<pair<pair<int, int>, int>> Kruskal() {
        vector<pair<pair<int, int>, int>> mstEdges;
        map<int, bool> visited;

        // Sort edges by weight
        vector<pair<pair<int, int>, int>> pairsDistances;
        for (const auto& entry : edges) {
            int from = entry.first;
            for (const auto& neighbor : entry.second) {
                int to = neighbor.first;
                int weight = neighbor.second;
                pairsDistances.push_back({{from, to}, weight});
            }
        }

        sort(pairsDistances.begin(), pairsDistances.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        for(const auto& pair : pairsDistances) {
            if (visited[pair.first.first] && visited[pair.first.second]) {
                continue; // Skip if both vertices are visited
            }
            mstEdges.push_back(pair);
            visited[pair.first.first] = true;
            visited[pair.first.second] = true;
        }

        return mstEdges;
    }

    void displayMST(const vector<pair<pair<int, int>, int>>& mstEdges) {
        cout << "Minimum Spanning Tree Edges:\n";
        for (const auto& edge : mstEdges) {
            cout << "(" << edge.first.first << ", " << edge.first.second << ") - Weight: " << edge.second << endl;
        }
    }
};

int main() {
    Graph graph;

    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 2, 1);
    graph.addEdge(3, 1, 2);
    graph.addEdge(4, 1, 3);
    graph.addEdge(2, 4, 1);

    graph.printGraph();

    vector<int> BFSResult = graph.BFS(2);
    cout << "BFS starting from vertex 2:\n";
    for (int i : BFSResult) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> DFSResult = graph.DFS(2);
    cout << "DFS starting from vertex 2:\n";
    for (int i : DFSResult) {
        cout << i << " ";
    }
    cout << endl;

    map<int, int> DijkstraResult = graph.Dijkstra(2);
    cout << "Dijkstra's Shortest Distances from Vertex 2:\n";
    for (const auto& entry : DijkstraResult) {
        int vertex = entry.first;
        int dist = entry.second;
        cout << "Vertex " << vertex << ": " << dist << '\n';
    }

    cout << "Prim's Algorithm: " << endl;
    int startVertex = 1;
    vector<pair<pair<int, int>, int>> primMSTEdges = graph.Prims(startVertex);
    graph.displayMST(primMSTEdges);

    cout << "Kruskal's Algorithm: " << endl;
    vector<pair<pair<int, int>, int>> kruskalMSTEdges = graph.Kruskal();
    graph.displayMST(kruskalMSTEdges);

    return 0;
}
