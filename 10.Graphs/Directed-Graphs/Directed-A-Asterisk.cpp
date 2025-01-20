#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cmath>
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
            for (int node : List[i])
                cout << node << " -> ";
            cout << "(END)" << endl;
        }
    }
    void displayMatrix() {
        cout << "[#] ADJACENCY MATRIX REPRESENTATION (Directed Graph) !!!" << endl;
        for (int i = 0; i < Vertex_Count; i++) {
            cout << "VERTEX [" << i << "] : ";
            for (int j = 0; j < Vertex_Count; j++)
                cout << Matrix[i][j] << " - ";
            cout << "(END)" << endl;
        }
    }
    int aStar(int start, int goal, vector<int>& heuristic) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> openList;
        unordered_map<int, int> gCost;
        unordered_map<int, int> cameFrom;
        gCost[start] = 0;
        openList.push({heuristic[start], start});
        while (!openList.empty()) {
            int current = openList.top().second;
            openList.pop();
            if (current == goal) {
                int pathNode = goal;
                cout << "[#] PATH: ";
                while (cameFrom.find(pathNode) != cameFrom.end()) {
                    cout << pathNode << " <- ";
                    pathNode = cameFrom[pathNode];
                }
                cout << start << endl;
                return gCost[goal];
            }
            for (int neighbor : List[current]) {
                int tentative_g = gCost[current] + 1;
                if (gCost.find(neighbor) == gCost.end() || tentative_g < gCost[neighbor]) {
                    gCost[neighbor] = tentative_g;
                    int f = tentative_g + heuristic[neighbor];
                    openList.push({f, neighbor});
                    cameFrom[neighbor] = current;
                }
            }
        }
        cout << "[!] NO PATH FOUND FROM " << start << " TO " << goal << endl;
        return -1;
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
    vector<int> heuristic = {4, 3, 2, 1, 0};
    g.aStar(0, 4, heuristic);
    return 0;
}
