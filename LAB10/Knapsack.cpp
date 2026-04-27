#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int knapsack(int n, int W, vector<int>& profit, vector<int>& weight) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    cout << "N\tAverage Execution Time (microseconds)\n";


    for (int n = 5; n <= 1000; n += 50) {

        vector<int> profit(n);
        vector<int> weight(n);

        
        for (int i = 0; i < n; i++) {
            profit[i] = (i + 1) * 10;   
            weight[i] = (i % 10) + 1;   
        }

        int W = n * 5; 

        long long totalTime = 0;
        int maxProfit = 0;

    
        for (int run = 1; run <= 10; run++) {

            auto start = high_resolution_clock::now();

            maxProfit = knapsack(n, W, profit, weight);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            totalTime += duration.count();
        }

        double averageTime = totalTime / 10.0;

        cout << n << "\t" << averageTime << "\n";
    }

    return 0;
}