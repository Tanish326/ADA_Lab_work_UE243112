#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;


bool linear_search(int *arr, int n, int target, int i) {
    if (i >= n) {
        return false;
    }  
    if (arr[i] == target){
         return true;
        }else{

    return linear_search(arr, n, target, i + 1);}
}

void get_random_array(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = (rand() % n) + 1;
}

int main() {
    int size[] = {5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140};
    int test = sizeof(size)/sizeof(size[0]);
    int ans[test][3];

    srand(time(0)); 
    int repeat = 1000000;
    for (int i = 0; i < test; i++) {
        int n = size[i];
        int *array = new int[n];
        get_random_array(array, n);

        int best_target = array[0];
        int worst_target = array[n-1];

        double best_case = 0, worst_case = 0;

        for (int j = 0; j < repeat; j++) {  
            auto start_best = high_resolution_clock::now();
            linear_search(array, n, best_target, 0);
            auto end_best = high_resolution_clock::now();
            best_case += duration_cast<nanoseconds>(end_best - start_best).count();

            auto start_worst = high_resolution_clock::now();
            linear_search(array, n, worst_target, 0);
            auto end_worst = high_resolution_clock::now();
            worst_case += duration_cast<nanoseconds>(end_worst - start_worst).count();
        }

        ans[i][0] = n;
        ans[i][1] = best_case / repeat;
        ans[i][2] = worst_case / repeat;

        delete[] array;  
    }

    
    cout << "Size\tBestCase(ns)\tWorstCase(ns)\n";
    for (int i = 0; i < test; i++)
        cout << ans[i][0] << "\t" << ans[i][1] << "\t" << ans[i][2] << "\n";

    return 0;
}
