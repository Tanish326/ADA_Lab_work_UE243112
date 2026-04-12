#include<iostream>
#include<vector>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;


int matrixChain(int n, vector<int>& p){
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len = 2; len < n; len++){
        for(int i = 1; i < n - len + 1; i++){
            int j = i + len - 1;
            dp[i][j] = 1e9;

            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n-1];
}

int main(){

    cout << "Size,Time(us)\n";

    
    for(int n = 5; n <= 1000; n += 50){

        vector<int> p(n);

        
        for(int i = 0; i < n; i++){
            p[i] = rand() % 50 + 1;   
        }

        int runs = 5;   
        long long total = 0;

        for(int r = 0; r < runs; r++){
            auto start = high_resolution_clock::now();

            matrixChain(n, p);

            auto end = high_resolution_clock::now();

            total += duration_cast<microseconds>(end - start).count();
        }

        cout << n << "," << total / runs << endl;
    }

    return 0;
}