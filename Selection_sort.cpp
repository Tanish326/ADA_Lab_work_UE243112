#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
void random_array(int *arr,int n){
    for(int i=0;i<n;i++){
        arr[i] = (rand()%n) + 1;
    }
}
void selection_sort(int array[],int n){
    for(int i=0;i<n-1;i++){
        int min_element = i;
        for(int j=i;j<n;j++){
            if(array[j]< array[min_element]){
              min_element = j;
            }
    
        }
        swap(&array[min_element],&array[i]);
    }
}


int main(){
    srand(1);
    int size_of_n[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
    int test = sizeof(size_of_n)/sizeof(size_of_n[0]);
    int repeat = 10;
    
    int ans[test][2];
    for(int i=0;i<test;i++){
        long long duration = 0;
        int n = size_of_n[i];
        int *copy = new int[n];
        random_array(copy,n);
       for(int j=0;j<repeat;j++){
        int *arr = new int[n];
       for(int a=0;a<n;a++){
            arr[a] = copy[a];
       }
        auto start = high_resolution_clock::now();
            selection_sort(arr,n);
            auto end = high_resolution_clock::now();
            duration += duration_cast<nanoseconds>(end-start).count();
       }
          ans[i][0] = n;
          ans[i][1] = duration/repeat;
    }
    for(int i=0;i<test;i++){
        cout<<ans[i][0]<<"\t"<<ans[i][1]<<"\n";
    }
    
   
    
}