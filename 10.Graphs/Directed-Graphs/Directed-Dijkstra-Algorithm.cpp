#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;
class Directed_Graph {
public:
    int Vertex_Count;
    vector<list<pair<int, int>>> List;
    vector<vector<int>> Matrix;
    Directed_Graph(int value) {
        Vertex_Count = value;
        List.resize(Vertex_Count);
        Matrix.resize(Vertex_Count, vector<int>(Vertex_Count, 0));
    }
    void addList(int u, int v, int weight) {
        List[u].push_back({v, weight});
    }
    void addMatrix(int u, int v, int weight) {
        Matrix[u][v] = weight;
    }
    void displayList() {
        cout << "[#] ADJACENCY LIST REPRESENTATION (Weighted Directed Graph) !!!" << endl;
        for (int i = 0; i < Vertex_Count; i++) {
            cout << "VERTEX [" << i << "] : ";
            for (auto& edge : List[i])
                cout << "(" << edge.first << ", " << edge.second << ") -> ";
            cout << "(END)" << endl;
        }
    }
    void displayMatrix() {
        cout << "[#] ADJACENCY MATRIX REPRESENTATION (Weighted Directed Graph) !!!" << endl;
        for (int i = 0; i < Vertex_Count; i++) {
            cout << "VERTEX [" << i << "] : ";
            for (int j = 0; j < Vertex_Count; j++)
                cout << Matrix[i][j] << " - ";
            cout << "(END)" << endl;
        }
    }
    void dijkstra(int source, int destination) {
        vector<int> dist(Vertex_Count, INT_MAX);
        vector<int> parent(Vertex_Count, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (u == destination) break;
            for (auto& edge : List[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[destination] == INT_MAX) cout << "[#] NO PATH EXISTS BETWEEN " << source << " & " << destination << " !!!" << endl;
        else {
            cout << "[#] SHORTEST DISTANCE FROM " << source << " TO " << destination << " HAS WEIGHT : " << dist[destination] << endl << ">>>[!] PATH : ";
            vector<int> path;
            for (int v = destination; v != -1; v = parent[v])
                path.push_back(v);
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];
                if (i > 0) cout << " -> ";
            }
            cout << endl;
        }
    }
};
int main() {
    Directed_Graph g(5);
    g.addList(0, 1, 10);
    g.addList(0, 4, 5);
    g.addList(1, 2, 3);
    g.addList(1, 3, 2);
    g.addList(3, 4, 4);
    g.addMatrix(0, 1, 10);
    g.addMatrix(0, 4, 5);
    g.addMatrix(1, 2, 3);
    g.addMatrix(1, 3, 2);
    g.addMatrix(3, 4, 4);
    g.displayList();
    g.displayMatrix();
    g.dijkstra(0, 3);
    return 0;
}
