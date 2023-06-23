#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Grafo {
    int V;             
    list<int>* adj;    

public:
    Grafo(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Função para adicionar uma aresta ao grafo
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Função para imprimir o caminho de um vértice s para um vértice d
    void printPath(vector<int>& parent, int d) {
        if (parent[d] == -1) {
            cout << d;
            return;
        }
        printPath(parent, parent[d]);
        cout << " -> " << d;
    }

    void BFS(int s, int d) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == d) {
                cout << "Caminho encontrado: ";
                printPath(parent, d);
                cout << endl;
                return;
            }

            for (auto neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = curr;
                    q.push(neighbor);
                }
            }
        }

        cout << "Caminho não encontrado!" << endl;
    }
};

int main() {
    // Criação do grafo
    Grafo g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    int source = 0;  // Vértice de partida
    int destination = 6;  // Vértice de destino

    cout << "Caminho de " << source << " para " << destination << ": ";
    g.BFS(source, destination);

    return 0;
}