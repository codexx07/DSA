#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T, int Nodes>
class Graph {
private:
    vector<list<T>> edges;

public:
    Graph() {
        edges.resize(Nodes);
    }

    void addEdge(int src, int dst) {
        edges[src].push_back(dst);
    }

    vector<T> BFS(int src) {
        vector<T> result;

        vector<bool> visited(Nodes, false);

        list<T> queue;

        visited[src] = true;
        queue.push_back(src);

        while (!queue.empty()) {
            T s = queue.front();
            result.push_back(s);
            queue.pop_front();

            for (const auto& i : edges[s]) {
                if (!visited[i]) {
                    visited[i] = true;
                    queue.push_back(i);
                }
            }
        }

        return result;
    }

    vector<T> DFSUtil(int v, vector<bool>& visited, vector<T>& result) {
        visited[v] = true;
        result.push_back(v);

        for (const auto& i : edges[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited, result);
            }
        }

        return result;
    }

    vector<T> DFS(int startVertex) {
        vector<bool> visited(Nodes, false);
        vector<T> result;

        return DFSUtil(startVertex, visited, result);
    }
};

int main() {
    Graph<int, 4> g;

    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS starting from vertex 0:" << endl;
    vector<int> result = g.BFS(2);

    for (const auto& vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;
    vector<int> result2 = g.DFS(2);
    for (const auto& vertex : result2) {
        cout << vertex << " ";
    }

    return 0;
}
