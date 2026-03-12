#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

struct Activity{
    int start;
    int finish;
};

void swap(Activity &a, Activity &b){
    Activity temp = a;
    a = b;
    b = temp;
}

int partition(Activity arr[], int low, int high){

    int pivot = arr[high].finish;
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j].finish <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(Activity arr[], int low, int high){

    if(low < high){

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int activitySelection(Activity arr[], int n){

    quickSort(arr,0,n-1);   

    int count = 1;
    int last = 0;

    for(int i=1;i<n;i++){
        if(arr[i].start >= arr[last].finish){
            count++;
            last = i;
        }
    }

    return count;
}

int main(){

    srand(time(0));

    double avgTime[200];
    int row = 0;

    for(int n=5;n<=1000;n+=5){

        double totalTime = 0;

        for(int k=0;k<100;k++){

            Activity arr[n];

            for(int i=0;i<n;i++){
                int s = rand()%1000;
                int f = s + rand()%50 + 1;

                arr[i].start = s;
                arr[i].finish = f;
            }

            auto start = high_resolution_clock::now();

            activitySelection(arr,n);

            auto end = high_resolution_clock::now();

            double time_taken = duration<double, micro>(end-start).count();

            totalTime += time_taken;
        }

        avgTime[row] = totalTime / 100.0;   
        row++;
    }

    for(int i=0;i<row;i++){
        cout<<"n = "<<(i+1)*5<<"  Avg Time = "<<avgTime[i]<<" microseconds"<<endl;
    }

    return 0;
}