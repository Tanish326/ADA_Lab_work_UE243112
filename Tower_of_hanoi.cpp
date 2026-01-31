#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

void towerOfHanoi(int n, char source, char helper, char destination) {
    if (n == 1) {
        return;
    }
    towerOfHanoi(n - 1, source, destination, helper);
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    int number_of_discs[] = {5,10,15,20,25,30}; 
    int test = sizeof(number_of_discs)/sizeof(number_of_discs[0]);
    
    long long ans[test][3]; 
    
    for(int i = 0; i < test; i++) {
        int n = number_of_discs[i];
        long long duration = 0;
        int repeat = 10;  
        
        for(int j = 0; j < repeat; j++) {
            auto start = high_resolution_clock::now();
            towerOfHanoi(n, 'A','B','C');
            auto end = high_resolution_clock::now();
            duration += duration_cast<nanoseconds>(end-start).count();
        }
        
        long long practical = duration / repeat;
        long long theoretical = pow(2, n) - 1; 
        
        ans[i][0] = n;
        ans[i][1] = practical;
        ans[i][2] = theoretical;
    }

    cout << "Discs\tPractical(ns)\tTheoretical\n";
    for(int i = 0; i < test; i++) {
        cout << ans[i][0] << "\t"
             << ans[i][1] << "\t"
             << ans[i][2] << "\n";
    }
}
