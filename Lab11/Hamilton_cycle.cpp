#include <bits/stdc++.h>
using namespace std;

#define V 5

bool checkingSafe(int v, bool graph[V][V], vector<int>& path, int pos) {

    if (!graph[path[pos - 1]][v])
        return false;

    
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}


bool hamiltonianCycle(bool graph[V][V], vector<int>& path, int pos) {


    if (pos == V) {
    
        return graph[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < V; v++) {

        if (checkingSafe(v, graph, path, pos)) {

            path[pos] = v;

            if (hamiltonianCycle(graph, path, pos + 1))
                return true;

        
            path[pos] = -1;
        }
    }

    return false;
}

int main() {

    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    vector<int> path(V, -1);
    path[0] = 0; 

    if (hamiltonianCycle(graph, path, 1)) {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0]; 
    } else {
        cout << "No Hamiltonian Cycle exists";
    }

    return 0;
}