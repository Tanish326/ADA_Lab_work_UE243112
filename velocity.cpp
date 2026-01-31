#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

int bounce(int vel , int n){
    if(vel < 1)
        return n;
    else
        return bounce(0.575 * vel, n + 1);
}

int main(){
    int velocities[] = {100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,4000,5000,6000,7000};
    const int TEST = sizeof(velocities)/sizeof(velocities[0]);
    
    double table[TEST][3]; 

    for(int i = 0; i < TEST; i++){
        int v = velocities[i];
        
    long long practical_time = 0;
        double theoretical = log(1.0/v) / log(0.575);
        if(theoretical < 0) theoretical = 0;  
        
        for(int i=0;i<100000;i++){
        auto start = high_resolution_clock::now();
        int n = bounce(v,0);
        auto end = high_resolution_clock::now();
        practical_time  += duration_cast<nanoseconds>(end - start).count();}
        
        table[i][0] = v;
        table[i][1] = practical_time/100000;
        table[i][2] = theoretical;
    }

    cout << "Velocity\tPractical(ns)\tTheoretical\n";
    for(int i=0;i<TEST;i++){
        cout << table[i][0] << "\t"
             << table[i][1] << "\t"
             << table[i][2] << "\n";
    }
}
