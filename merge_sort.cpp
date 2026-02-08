#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std;
using namespace std::chrono;

void random_array_generator(int a[], int n){
    for(int i=0;i<n;i++)
        a[i] =  rand()%n + 1;
}

void merge_two_sorted(int a[], int low, int mid, int high){
    int n = high - low + 1;
    int *temp = new int[n];

    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high){
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= high) temp[k++] = a[j++];

    for(int x = 0; x < n; x++)
        a[low + x] = temp[x];

    delete[] temp;
}

void divide(int a[], int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    divide(a, low, mid);
    divide(a, mid + 1, high);
    merge_two_sorted(a, low, mid, high);
}

int main(){
    srand(1);
    int cases[] = {100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000,2000000,3000000,4000000};
    int t = sizeof(cases)/sizeof(cases[0]);

    cout << "N\tTime(ns)\n";

    for(int i = 0; i < t; i++){
        int n = cases[i];
        double total = 0;

        for(int r = 0; r < 10; r++){
            int *arr = new int[n];
            random_array_generator(arr, n);

            auto start = high_resolution_clock::now();
            divide(arr, 0, n-1);
            auto end = high_resolution_clock::now();

            total += duration_cast<milliseconds>(end - start).count();
            delete[] arr;
        }

        cout << n << "\t" << total/10 << endl;
    }
}
