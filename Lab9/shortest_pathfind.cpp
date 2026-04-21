#include <bits/stdc++.h>
using namespace std;

#define INF 1e9


void printPath(int u, int v, vector<vector<int>>& nextNode) {
    if (nextNode[u][v] == -1) {
        cout << "No Path Exists\n";
        return;
    }

    cout << u << " ";

    while (u != v) {
        u = nextNode[u][v];
        cout << u << " ";
    }

    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m; 

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> nextNode(n + 1, vector<int>(n + 1, -1));

    
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        nextNode[i][i] = i;
    }


    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        dist[u][v] = wt;
        dist[v][u] = wt; 

        nextNode[u][v] = v;
        nextNode[v][u] = u;
    }

    
    for (int via = 1; via <= n; via++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (dist[i][via] == INF || dist[via][j] == INF)
                    continue;

                if (dist[i][via] + dist[via][j] < dist[i][j]) {
                    dist[i][j] = dist[i][via] + dist[via][j];

                    
                    nextNode[i][j] = nextNode[i][via];
                }
            }
        }
    }

    int source, destination;
    cin >> source >> destination;

    cout << "Shortest Distance: " << dist[source][destination] << endl;

    cout << "Shortest Path: ";
    printPath(source, destination, nextNode);

    return 0;
}