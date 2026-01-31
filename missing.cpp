#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int findMissingIndexBit0(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int expected_bit0;
        if(i%2==0){
            expected_bit0 = 1;
        }else{
            expected_bit0 = 0;
        }
        int actual_bit0 = arr[i] & 1;
        if(actual_bit0 != expected_bit0) {
            return i;
        }
    }
    return n-1;
}

int main() {
    srand(1);
    int n_values[] = {100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,3500,4000};
    int test = sizeof(n_values)/sizeof(n_values[0]);
    int repeat = 100000;
    long long ans[test][2]; 

    for(int i = 0; i < test; i++){
        int n = n_values[i];
        int *arr = new int[n-1];

        
        for(int j = 0; j < n-1; j++) arr[j] = j;

        long long total_time = 0;
        for(int r = 0; r < repeat; r++){
            auto start = high_resolution_clock::now();
            int index = findMissingIndexBit0(arr, n);
            auto end = high_resolution_clock::now();
            total_time += duration_cast<nanoseconds>(end-start).count();
        }

        ans[i][0] = n;
        ans[i][1] = total_time / repeat; 
        delete[] arr;
    }

    cout << "n\tPractical(ns)\n";
    for(int i = 0; i < test; i++)
        cout << ans[i][0] << "\t" << ans[i][1] << "\n";

    return 0;
}
