#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

struct Edge {
    int weight, u, v;
    bool operator>(const Edge& other) const { return weight > other.weight; }
};

void prims(int n, vector<vector<int>>& cost) {
    vector<int> near(n, -1);
    vector<bool> inMST(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    inMST[0] = true;
    for (int v = 1; v < n; v++)
        pq.push({cost[0][v], 0, v}), near[v] = 0;

    while (!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        if (inMST[e.v]) continue;
        inMST[e.v] = true;

        for (int k = 0; k < n; k++) {
            if (!inMST[k]) {
                pq.push({cost[e.v][k], e.v, k});
                if (near[k] == -1 || cost[e.v][k] < cost[k][near[k]])
                    near[k] = e.v;
            }
        }
    }
}

int main() {
    srand(time(0));
    const int MAX_N = 100; 
    double avgTime[200];
    int row = 0;

    for (int n = 5; n <= MAX_N; n += 5) {
        double totalTime = 0;
        for (int k = 0; k < 10; k++) {
            vector<vector<int>> cost(n, vector<int>(n));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    cost[i][j] = (i==j ? 0 : rand()%100+1);

            auto start = high_resolution_clock::now();
            prims(n, cost);
            auto end = high_resolution_clock::now();

            totalTime += duration<double, micro>(end - start).count();
        }
        avgTime[row++] = totalTime / 10.0;
    }

    for (int i = 0; i < row; i++)
        cout << "n = " << (i + 1) * 5 << "  Avg Time = " << avgTime[i] << " microseconds\n";

    return 0;
}