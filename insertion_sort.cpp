#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void makeRandom(int *a, int n){
    for(int i = 0; i < n; i++)
        a[i] = (rand() % n) + 1; 
}


void makeBest(int *a, int n){
    for(int i = 0; i < n; i++)
        a[i] = i;
        
}

void makeWorst(int *a, int n){
    
    for(int i = n-1; i >=0; i--){
        a[i] = i;
        
    }
}

void sortInsert(int *a, int n){
    for(int x = 1; x < n; x++){
        int cur = a[x];
        int y = x - 1;
        while(y >= 0 && a[y] > cur){
            a[y + 1] = a[y];
            y--;
        }
        a[y + 1] = cur;
    }
}

long long measure(int *a, int n){
    auto st = chrono::high_resolution_clock::now();
    sortInsert(a, n);
    auto en = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(en - st).count();
}

int main(){
    srand((unsigned)time(0));

    int dataSize[] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000};
    int total = sizeof(dataSize)/sizeof(dataSize[0]);

    double table[total][4];

    for(int i = 0; i < total; i++){
        int n = dataSize[i];
        int *arr = new int[n];

        double tBest = 0, tAvg = 0, tWorst = 0;

        for(int r = 0; r < 10; r++){

            makeBest(arr, n);
            tBest += measure(arr, n);

            makeRandom(arr, n);
            tAvg += measure(arr, n);

            makeWorst(arr, n);
            tWorst += measure(arr, n);
        }

        table[i][0] = n;
        table[i][1] = tBest / 10;
        table[i][2] = tAvg / 10;
        table[i][3] = tWorst / 10;

        delete[] arr;
    }

    cout << "\nN\tBest\tAverage\tWorst\n";
    for(int i = 0; i < total; i++){
        cout << table[i][0] << "\t"
             << table[i][1] << "\t"
             << table[i][2] << "\t"
             << table[i][3] << endl;
    }

    return 0;
}
