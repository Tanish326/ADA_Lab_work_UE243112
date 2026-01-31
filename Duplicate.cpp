#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void find_duplicates(int array[], int size){
    int c = 0;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(array[i] == array[j]){
                c++;
                break;
            }
        }
    }
}

void get_random(int *arr,int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % n;
    }
}

int main(){
    srand(1);

    int n_values[] = {100,500,1000,1500,2000,2500,3000};
    int test = sizeof(n_values)/sizeof(n_values[0]);

    int repeat = 50;   
    
    long long ans[7][2];  

    for(int i = 0; i < test; i++){
        int n = n_values[i];
        int *arr = new int[n];
        get_random(arr,n);

        long long total_time = 0;

        for(int r = 0; r < repeat; r++){
            auto start = high_resolution_clock::now();
            find_duplicates(arr, n);
            auto end = high_resolution_clock::now();
            total_time += duration_cast<nanoseconds>(end - start).count();
        }

        ans[i][0] = n;
        ans[i][1] = total_time / repeat;

        delete[] arr;
    }

    cout << "\nN\tAvg Time (ns)\n";
    for(int i = 0; i < test; i++){
        cout << ans[i][0] << "\t" << ans[i][1] << endl;
    }

    return 0;
}
