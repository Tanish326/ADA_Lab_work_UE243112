#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

struct Item {
    int profit;
    int weight;
};


void merge(Item arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Item* L = new Item[n1];
    Item* R = new Item[n2];

    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int i=0;i<n2;i++) R[i] = arr[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i].weight <= R[j].weight){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void mergeSort(Item arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

double fractionalKnapsack(int W, Item arr[], int n){
    mergeSort(arr,0,n-1); 

    double totalProfit = 0.0;

    for(int i=0;i<n;i++){
        if(W >= arr[i].weight){
            W -= arr[i].weight;
            totalProfit += arr[i].profit;
        } else {
            totalProfit += arr[i].profit * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    const int step = 1000;
    const int maxSize = 10000;
    const int runs = 10;

    long long results[maxSize/step][2]; 

    srand(time(0));

    for(int n = step, idx = 0; n <= maxSize; n += step, idx++){
        long long totalTime = 0;

        for(int r = 0; r < runs; r++){
            int W = n/2 + rand()%n; 

            Item* items = new Item[n];
            for(int i=0;i<n;i++){
                items[i].profit = 1 + rand()%100;
                items[i].weight = 1 + rand()%50;
            }

            auto start = high_resolution_clock::now();
            double profit = fractionalKnapsack(W, items, n);
            auto stop = high_resolution_clock::now();

            auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
            totalTime += duration.count();

            delete[] items;
        }

        long long avgTime = totalTime / runs;
        results[idx][0] = n;
        results[idx][1] = avgTime;
    }

    
    cout << "Size\tAverage Time (microseconds)\n";
    for(int i=0; i<maxSize/step; i++){
        cout << results[i][0] << "\t" << results[i][1] << endl;
    }

    return 0;
}