#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

int power(int a , int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int half = power(a , b/2);
        return half * half;
    } else {
        return a * power(a, b-1);
    }
}

int main(){
    int a = 2;
    

    vector<vector<long long>> data; 
    

    for(int b = 1; b <= 50; b++){
        long long totalTime = 0;

        for(int run = 1; run <= 10; run++){
            auto start = high_resolution_clock::now();

            for(int k = 0; k < 100000; k++){
                power(a, b);
            }

            auto end = high_resolution_clock::now();
            totalTime += duration_cast<nanoseconds>(end - start).count();
        }

        long long avgTime = totalTime / 10;
        data.push_back({b, avgTime});
    }


    cout << "Stored 2D Array:"<<endl;
    for(auto &row : data){
        cout << row[0] << " " << row[1] << endl;
    }
}
