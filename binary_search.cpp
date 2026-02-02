#include<iostream>
#include<chrono>
#include<ctime>
#include<chrono>
#include<stdlib.h>
using namespace std;
using namespace std::chrono;

void make_sorted_array(int *a,int n){
    for(int i=0;i<n;i++){
        a[i] = i;
    }
   
}


bool BS(int array[],int low , int high,int target){
    if(low>high){
        return false;
    }
    int middle = low + (high - low)/2;
    if(array[middle]==target){
        return true;
    }else if(array[middle]>target){
       return BS(array,low,middle-1,target);
    
    }else{
        return BS(array,middle+1,high,target);
    }
}

int main(){
    srand(1);
    int size[] = {10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,110000,120000,130000,140000,150000,160000,170000,180000,190000,200000,210000,220000,230000,240000,250000};
    int test = 25;
    int target;
    int repeat = 1000000;
    double ans[test][5];
    for(int i=0;i<test;i++){
        int n = size[i];
       int *arr = new int[n];
          double duration_best = 0;
          double duration_avg = 0;
          double duration_worst1 = 0;
          double duration_worst2 = 0;
         make_sorted_array(arr,n);
        
        for(int j=0;j<repeat;j++){
      
      
         int best_case_target = arr[n/2];
     int worst_case1_target = -1;
     int worst_case2_target = arr[n-1];
     int avg_case_target = arr[rand()%n];
     
        auto best_start = high_resolution_clock::now();
        BS(arr,0,n-1,best_case_target);
        auto best_stop = high_resolution_clock::now();
         
         duration_best += duration_cast<nanoseconds>(best_stop - best_start).count();
        
         auto start = high_resolution_clock::now();
        BS(arr,0,n-1,worst_case1_target);
        auto stop = high_resolution_clock::now();
         
         duration_worst1 += duration_cast<nanoseconds>(stop - start).count();
        
         auto worst_start = high_resolution_clock::now();
        BS(arr,0,n-1,worst_case2_target);
        auto worst_stop = high_resolution_clock::now();
         
         duration_worst2 += duration_cast<nanoseconds>(worst_stop - worst_start).count();
        
         auto avg_start = high_resolution_clock::now();
        BS(arr,0,n-1,avg_case_target);
        auto avg_stop = high_resolution_clock::now();
         
         duration_avg += duration_cast<nanoseconds>(avg_stop - avg_start).count();
        
        
        
        }

        ans[i][0] = n;        
        ans[i][1] = duration_best/repeat; 
        ans[i][2] = duration_worst1/repeat;
        ans[i][3] = duration_worst2/repeat;
        ans[i][4] = duration_avg/repeat;

        delete[] arr;
    }
      cout<<"n"<<"\t" <<" best_case"<<" worst_case1"<<" worst_case2 "<<"avg_case"<<"\n";
        
    for(int a=0;a<test;a++){
      
       cout<<ans[a][0]<<"\t"<<ans[a][1]<<"\t"<<ans[a][2]<<"\t"<<ans[a][3]<<"\t"<<ans[a][4]<<"\n";
    }
    
   
}