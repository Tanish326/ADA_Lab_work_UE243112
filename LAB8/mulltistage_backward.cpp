#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;

int multistage(int n, vector<vector<int>>& cost) {
    vector<int> mincost(n + 1, INT_MAX);

    mincost[n] = 0;

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (cost[i][j] != 0) {
                if (mincost[i] > cost[i][j] + mincost[j]) {
                    mincost[i] = cost[i][j] + mincost[j];
                }
            }
        }
    }

    return mincost[1];
}

int main() {

    cout << "Size,Time(us)\n";

    for (int n = 100; n <= 1000; n += 100) {

        
        vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cost[i][j] = rand() % 100 + 1; 
            }
        }

    
        auto start = high_resolution_clock::now();

        multistage(n, cost);

        
        auto end = high_resolution_clock::now();

        
        auto duration = duration_cast<microseconds>(end - start);

        cout << n << "," << duration.count() << endl;
    }

    return 0;
}