#include <iostream>
using namespace std;

class graph {
    int n;
    int graph1[10][10];

public:
    graph() {
        cout << "Enter number of vertices: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    graph1[i][j] = 0;
                } else {
                    graph1[i][j] = 999;
                }
            }
        }
    }

    void create() {
        int v1, v2, cost, ans;
        do {
            cout << "Enter source vertex (0 to " << n - 1 << "): ";
            cin >> v1;
            cout << "Enter destination vertex (0 to " << n - 1 << "): ";
            cin >> v2;
            cout << "Enter cost of edge: ";
            cin >> cost;

            if (v1 >= 0 && v1 < n && v2 >= 0 && v2 < n) {
                graph1[v1][v2] = cost;
            } else {
                cout << "Invalid vertex input. Edge not added." << endl;
            }

            cout << "One more edge? (1 for yes, 0 for no): ";
            cin >> ans;
        } while (ans == 1);
    }

    void display() 
    {
        cout << "Adjacency Matrix: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << graph1[i][j] << " ";
            }
            cout << endl;
        }
    }
    void warshall()
    {
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                for(int i=0;i<n;i++)
                {
                    if(graph1[i][k]+graph1[k][j]<graph1[i][j])
                     {
                        graph1[i][j]=graph1[i][k]+graph1[k][j];
                     }
                }
            }
        }
    }
    
    
};

int main() {
    graph g;
    g.create();
    g.display();
    g.warshall();
    g.display();
    return 0;
}
