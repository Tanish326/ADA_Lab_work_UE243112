#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define INF 1e9

void findShortestPath(int n) {
    vector<vector<int>> dist(n, vector<int>(n, INF));

    
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (int j = i + 1; j < n; j++) {
            int wt = rand() % 100 + 1; 
            dist[i][j] = wt;
            dist[j][i] = wt;
        }
    }

    
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][via] != INF && dist[via][j] != INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }
    }
}

int main() {
    srand(time(0));

    cout << "N\tTime (microseconds)\n";

    for (int n = 5; n <= 1000; n += 50) {

        auto start = high_resolution_clock::now();

        findShortestPath(n);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}