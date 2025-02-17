#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adj;
    Graph(int value) : V(value) { adj.resize(V); }
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }
    void prims() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, INT_MAX), parent(V, -1);
        vector<bool> inMST(V, false);
        pq.push({0, 0});
        key[0] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }
        for (int i = 1; i < V; i++)
            cout << parent[i] << " -> " << i << endl;
    }
    void kruskal() {
        vector<pair<int, pair<int, int>>> edges;
        for (int u = 0; u < V; u++) {
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                edges.push_back({weight, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        for (auto& edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int weight = edge.first;
            if (find(parent, u) != find(parent, v)) {
                cout << u << " -> " << v << endl;
                union_sets(parent, rank, u, v);
            }
        }
    }

private:
    int find(vector<int>& parent, int u) {
        if (parent[u] != u) parent[u] = find(parent, parent[u]);
        return parent[u];
    }
    void union_sets(vector<int>& parent, vector<int>& rank, int u, int v) {
        int root_u = find(parent, u);
        int root_v = find(parent, v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) parent[root_v] = root_u;
            else if (rank[root_u] < rank[root_v]) parent[root_u] = root_v;
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};
int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    cout << "[#] Directed-Graph MST using Prim's Algorithm:" << endl;
    g.prims();
    cout << "[#] Directed-Graph MST using Kruskal's Algorithm:" << endl;
    g.kruskal();
    return 0;
}
