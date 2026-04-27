#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;


int tsp(int i, vector<int> S, vector<vector<int>>& cost) {

    
    if (S.empty()) {
        return cost[i][0];
    }

    int minCost = 99999;

    
    for (int k = 0; k < S.size(); k++) {

        int city = S[k];

        vector<int> newS = S;

        
        newS.erase(newS.begin() + k);

        int currentCost =
            cost[i][city] +
            tsp(city, newS, cost);

        minCost = min(minCost, currentCost);
    }

    return minCost;
}

int main() {

    cout << "n\tAverage Time (microseconds)\n";

    for (int n = 5; n <= 15; n++) {

    

        vector<vector<int>> cost(n, vector<int>(n));

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    cost[i][j] = 0;
                else
                    cost[i][j] = (i + j + 1) * 5;
            }
        }

        long long totalTime = 0;

        
        for (int run = 1; run <= 10; run++) {

            vector<int> S;

            
            for (int i = 1; i < n; i++) {
                S.push_back(i);
            }

            auto start = high_resolution_clock::now();

            int answer = tsp(0, S, cost);

            auto stop = high_resolution_clock::now();

            auto duration =
                duration_cast<microseconds>(stop - start);

            totalTime += duration.count();
        }

        double averageTime = totalTime / 10.0;

        cout << n << "\t"
             << averageTime << endl;
    }

    return 0;
}