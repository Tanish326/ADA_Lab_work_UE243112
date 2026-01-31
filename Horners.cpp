#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

int hornerRec(int a[], int n, int x) {
    if (n == 1){
        return a[0];}

    return hornerRec(a, n - 1, x) * x + a[n - 1];
}

int main() {
    srand(time(0));

    const int TEST = 20;                
    int sizes[TEST] = {10,20,30,40,50,60,70,80,90,100,
                       110,120,130,140,150,160,170,180,190,200};

    long long table[TEST][3]; 

    for (int i = 0; i < TEST; i++) {
        int n = sizes[i];
        int *a = new int[n];

        for (int j = 0; j < n; j++)
            a[j] = rand() % 10;

        int x = rand() % 10 + 1;

        long long total = 0;

        for (int k = 0; k < 1000; k++) {   
            auto start = high_resolution_clock::now();
            hornerRec(a, n, x);
            auto end = high_resolution_clock::now();
            total += duration_cast<nanoseconds>(end - start).count();
        }

        table[i][0] = n;
        table[i][1] = total / 1000;  
        table[i][2] = n;             

        delete[] a;
    }

    cout << "n\tPractical(ns)\tTheoretical(n)\n";
    for (int i = 0; i < TEST; i++) {
        cout << table[i][0] << "\t"
             << table[i][1] << "\t"
             << table[i][2] << "\n";
    }
}
