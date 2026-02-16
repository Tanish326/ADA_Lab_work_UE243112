#include<iostream>
using namespace std;
void merge(int array[],int low,int high){
  if(low==high){
    return;
    
  }
  int mid = (low + high)/2;
  merge(array,low,mid-1);/
  merge(array,mid+1,high);
}