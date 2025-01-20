#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;
class Undirected_Graph {
public:
    int Vertex_Count;
    vector<list<int>> List;
    vector<vector<int>> Matrix;
    Undirected_Graph(int value) {
        Vertex_Count = value;
        List.resize(Vertex_Count);
        Matrix.resize(Vertex_Count, vector<int>(Vertex_Count, 0));
    }
    void addList(int u, int v) {
        List[u].push_back(v);
        List[v].push_back(u);
    }
    void addMatrix(int u, int v) {
        Matrix[u][v] = 1;
        Matrix[v][u] = 1;
    }
    void displayList() {
        cout << "[#] ADJACENCY LIST REPRESENTATION (Undirected Graph) !!!" << endl;
        for (int i = 0; i < Vertex_Count; i++) {
            cout << "VERTEX [" << i << "] : ";
            for (int node : List[i])
                cout << node << " -> ";
            cout << "(END)" << endl;
        }
    }
    void displayMatrix() {
        cout << "[#] ADJACENCY MATRIX REPRESENTATION (Undirected Graph) !!!" << endl;
        for (int i = 0; i < Vertex_Count; i++) {
            cout << "VERTEX [" << i << "] : ";
            for (int j = 0; j < Vertex_Count; j++)
                cout << Matrix[i][j] << " - ";
            cout << "(END)" << endl;
        }
    }
    void BFS(int start) {
        vector<bool> visited(Vertex_Count, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "[#] BFS USING QUEUE : ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " -> ";
            for (int neighbor : List[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "(END)" << endl;
    }
    void DFS(int start) {
        vector<bool> visited(Vertex_Count, false);
        stack<int> s;
        s.push(start);
        cout << "[#] DFS USING STACK : ";
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            if (!visited[current]) {
                visited[current] = true;
                cout << current << " -> ";
            }
            for (int neighbor : List[current])
                if (!visited[neighbor]) s.push(neighbor);
        }
        cout << "(END)" << endl;
    }
};
int main() {
    Undirected_Graph g(5);
    g.addList(0, 1);
    g.addList(1, 2);
    g.addList(2, 3);
    g.addList(3, 4);
    g.addList(4, 0);
    g.addMatrix(0, 4);
    g.addMatrix(4, 3);
    g.addMatrix(3, 2);
    g.addMatrix(2, 1);
    g.addMatrix(1, 0);
    g.displayList();
    g.displayMatrix();
    g.BFS(0);
    g.DFS(0);
    return 0;
}
