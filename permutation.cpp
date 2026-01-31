#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

void randomString(char s[], int n) {
    const char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++)
        s[i] = letters[rand() % 26];
    s[n] = '\0';
}

void swap(char &a, char &b) {
   char t = a;
   a = b;
   b = t;
}


long long permutation(char s[], int index, int n) {
    if (index == n){
        return 1;   }

    long long count = 0;
    for (int i = index; i < n; i++) {
        swap(s[index], s[i]);
        count += permutation(s, index + 1, n);
        swap(s[index], s[i]);
    }
    return count;
}

long long factorial(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++){
        f *= i;}
    return f;
}

int main() {
    srand(time(0));

    const int MAX_N = 10;   
    long long table[MAX_N + 1][3];

    for (int n = 1; n <= MAX_N; n++) {
        char s[n + 1];
        randomString(s, n);

        long long total_time = 0;

        for (int i = 0; i < 10; i++) { 
            auto start = high_resolution_clock::now();
            permutation(s, 0, n);
            auto end = high_resolution_clock::now();
            total_time += duration_cast<nanoseconds>(end - start).count();
        }

        table[n][0] = n;
        table[n][1] = total_time / 10;   
        table[n][2] = factorial(n);     
    }

    cout << "n\tPractical(ns)\tTheoretical(n!)\n";
    for (int i = 1; i <= MAX_N; i++) {
        cout << table[i][0] << "\t"
             << table[i][1] << "\t"
             << table[i][2] << "\n";
    }
}
