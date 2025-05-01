#include<iostream>
using namespace std;

int graph[10][10], visitedDFS[10], visitedBFS[10];
int stk[10], top = -1;           // Stack for DFS
int qu[10], front = 0, rear = 0; // Queue for BFS

int main(){
    int m, n, i, j, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEnter edges (vertex1 vertex2):\n";
    for (int k = 0; k < m; k++) {
        cin >> i >> j;
        graph[i][j] = 1;
        graph[j][i] = 1; // undirected graph
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << " " << graph[i][j];
        }
        cout << endl;
    }

    // DFS
    cout << "\nEnter starting vertex for DFS: ";
    cin >> v;
    cout << "DFS Traversal: ";

    visitedDFS[v] = 1;
    cout << v << " ";
    stk[++top] = v;

    while (top != -1) {
        int node = stk[top], found = 0;
        for (j = 0; j < n; j++) {
            if (graph[node][j] == 1 && !visitedDFS[j]) {
                cout << j << " ";
                visitedDFS[j] = 1;
                stk[++top] = j;
                found = 1;
                break;
            }
        }
        if (!found)
            top--;
    }

    // BFS
    cout << "\n\nEnter starting vertex for BFS: ";
    cin >> v;
    cout << "BFS Traversal: ";

    visitedBFS[v] = 1;
    cout << v << " ";
    qu[rear++] = v;

    while (front < rear) {
        int curr = qu[front++];
        for (j = 0; j < n; j++) {
            if (graph[curr][j] == 1 && !visitedBFS[j]) {
                cout << j << " ";
                visitedBFS[j] = 1;
                qu[rear++] = j;
            }
        }
    }

    return 0;
}
