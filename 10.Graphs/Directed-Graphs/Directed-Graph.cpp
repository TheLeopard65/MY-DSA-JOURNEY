#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Directed_Graph {
public:
    int Vertex_Count;
    vector<list<int>> List;
    vector<vector<int>> Matrix;
    Directed_Graph(int value) {
        Vertex_Count = value;
        List.resize(Vertex_Count);
        Matrix.resize(Vertex_Count, vector<int>(Vertex_Count, 0));
    }
    void addList(int u, int v) {
        List[u].push_back(v);
    }
    void addMatrix(int u, int v) {
        Matrix[u][v] = 1;
    }
    void displayList() {
        cout << "[#] ADJACENCY LIST REPRESENTATION (Directed Graph) !!!" << endl;
        for (int i = 0; i < Vertex_Count; i++) {
            cout << "VERTEX [" << i << "] : ";
            for (int node : List[i]) {
                cout << node << " -> ";
            }
            cout << "(END)" << endl;
        }
    }
    void displayMatrix() {
        cout << "[#] ADJACENCY MATRIX REPRESENTATION (Directed Graph) !!!" << endl;
        for (int i = 0; i < Vertex_Count; i++) {
            cout << "VERTEX [" << i << "] : ";
            for (int j = 0; j < Vertex_Count; j++) {
                cout << Matrix[i][j] << " - ";
            }
            cout << "(END)" << endl;
        }
    }
};
int main() {
    Directed_Graph g(5);
    g.addList(0, 1);
    g.addList(0, 4);
    g.addList(1, 2);
    g.addList(1, 3);
    g.addList(3, 4);
    g.addMatrix(0, 1);
    g.addMatrix(0, 4);
    g.addMatrix(1, 2);
    g.addMatrix(1, 3);
    g.addMatrix(3, 4);
    g.displayList();
    g.displayMatrix();
    return 0;
}
