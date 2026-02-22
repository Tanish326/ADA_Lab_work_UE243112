
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;

int minVal, maxVal;

void MinMax(int arr[], int low, int high) {

    if (low == high) {
        if (arr[low] < minVal)
            minVal = arr[low];
        if (arr[low] > maxVal)
            maxVal = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (arr[low] < minVal)
                minVal = arr[low];
            if (arr[high] > maxVal)
                maxVal = arr[high];
        } else {
            if (arr[high] < minVal)
                minVal = arr[high];
            if (arr[low] > maxVal)
                maxVal = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;

    MinMax(arr, low, mid);
    MinMax(arr, mid + 1, high);
}

int main() {

    srand(1);   

    const int maxSize = 20000;
    const int step = 1000;
    const int runs = 1000;

    int rows = maxSize / step;
    double avgTime[rows];  

    for (int i = 1; i <= rows; i++) {

        int n = i * step;
        int *arr = new int[n];

        double totalTime = 0;

        for (int j = 0; j < runs; j++) {

            for (int k = 0; k < n; k++) {
                arr[k] = rand() % 100000;
            }

            minVal = arr[0];
            maxVal = arr[0];

            auto start = high_resolution_clock::now();

            MinMax(arr, 0, n - 1);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);

            totalTime += duration.count();
        }

        avgTime[i - 1] = totalTime / runs;

        delete[] arr;
    }
    cout << "Size\tAverage Time (microseconds)\n";

    for (int i = 0; i < rows; i++) {
        cout << (i + 1) * step << "\t" << avgTime[i] << endl;
    }

    return 0;
}