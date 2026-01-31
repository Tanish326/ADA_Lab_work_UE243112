#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int sum_n(int n) {
    if(n == 0){
        return 0;
    }
    return n + sum_n(n-1);
}

int main() {
    int n_values[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int test = sizeof(n_values)/sizeof(n_values[0]);
    int repeat = 10000;
    long long ans[test][3]; 

    for(int i=0;i<test;i++){
        int n = n_values[i];
        long long total_time = 0;
        int result = 0;

        for(int j=0;j<repeat;j++){
            auto start = high_resolution_clock::now();
            result = sum_n(n);
            auto end = high_resolution_clock::now();
            total_time += duration_cast<nanoseconds>(end - start).count();
        }

        ans[i][0] = n;                      
        ans[i][1] = total_time / repeat;    
        ans[i][2] = (long long)n*(n+1)/2;  
    }

    cout << "n\tPractical(ns)\tTheoretical\n";
    for(int i=0;i<test;i++){
        cout << ans[i][0] << "\t" << ans[i][1] << "\t" << ans[i][2] << "\n";
    }
}
