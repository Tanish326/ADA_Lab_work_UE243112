#include <bits/stdc++.h>
using namespace std;

#define N 4

bool checkingSafe(int v, bool graph[N][N], vector<int>& color, int c) {
    for (int i = 0; i < N; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool solve(int v, bool graph[N][N], int m, vector<int>& color) {

    
    if (v == N)
        return true;

    
    for (int c = 1; c <= m; c++) {

        if (checkingSafe(v, graph, color, c)) {

            color[v] = c;

            if (solve(v + 1, graph, m, color))
                return true;

            
            color[v] = 0;
        }
    }

    return false;
}

int main() {

    bool graph[N][N] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; 

    vector<int> color(N, 0);

    if (solve(0, graph, m, color)) {
        cout << "Solution exists:\n";
        for (int i = 0; i < N; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}