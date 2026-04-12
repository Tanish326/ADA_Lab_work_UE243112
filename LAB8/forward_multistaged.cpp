#include<iostream>
#include<vector>
#include<climits>
#include<chrono>
using namespace std;
using namespace std::chrono;


int forward_multistage(int n, vector<vector<int>>& cost) {
    vector<int> dist(n, INT_MAX);

    dist[0] = 0; 

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(cost[i][j] != 0){
                if(dist[j] > dist[i] + cost[i][j]){
                    dist[j] = dist[i] + cost[i][j];
                }
            }
        }
    }

    return dist[n-1];
}

int main(){

    cout << "Size,Time(us)\n";

    for(int n = 100; n <= 1000; n += 100){

    
        vector<vector<int>> cost(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                cost[i][j] = rand() % 100 + 1; 
            }
        }

        int runs = 10;
        long long total = 0;

        for(int r = 0; r < runs; r++){
            auto start = high_resolution_clock::now();

            forward_multistage(n, cost);

            auto end = high_resolution_clock::now();

            total += duration_cast<microseconds>(end - start).count();
        }

        cout << n << "," << total / runs << endl;
    }

    return 0;
}