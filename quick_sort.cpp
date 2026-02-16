#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);

        if (i >= j) return j;

        swap(&a[i], &a[j]);
    }
}

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quick_sort(a, low, p);
        quick_sort(a, p + 1, high);
    }
}
void avg_case(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand()%n + 1;
}


void worst_case(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = n - i;
}

int main() {
    srand(1);


    int cases[] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
    int t = sizeof(cases) / sizeof(cases[0]);

    cout << "N\tBest(ms)\tWorst(ms)\n";

    for (int i = 0; i < t; i++) {
        int n = cases[i];
        double best_time = 0, worst_time = 0;

        for (int r = 0; r < 5; r++) {
            int *arr = new int[n];

        
            avg_case(arr, n);
            auto s1 = high_resolution_clock::now();
            quick_sort(arr, 0, n - 1);
            auto e1 = high_resolution_clock::now();
            best_time += duration_cast<milliseconds>(e1 - s1).count();

        
            worst_case(arr, n);
            auto s2 = high_resolution_clock::now();
            quick_sort(arr, 0, n - 1);
            auto e2 = high_resolution_clock::now();
            worst_time += duration_cast<milliseconds>(e2 - s2).count();

            delete[] arr;
        }

        cout << n << "\t" << best_time / 5 << "\t\t" << worst_time / 5 << endl;
    }

    return 0;
}
