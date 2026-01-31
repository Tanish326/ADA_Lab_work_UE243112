#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


void generateTruth(int n, string s) {
    if (s.length() == n) {
       return;
    }
    generateTruth(n, s + "0");
    generateTruth(n, s + "1");
}

int main() {
    long long table[21][2]; 

    cout << "n\tTime (ns)\n";

    for(int n = 1; n <= 20; n++) {
        auto start = high_resolution_clock::now();
        generateTruth(n, "");
        auto end = high_resolution_clock::now();

        long long time = duration_cast<nanoseconds>(end - start).count();
        table[n][0] = n;
        table[n][1] = time;

        cout << n << "\t" << time << endl;
    }

    cout << "\nStored 2D Array:\n";
    for(int n = 1; n <= 20; n++) {
        cout << table[n][0] << " " << table[n][1] << endl;
    }

    return 0;
}
