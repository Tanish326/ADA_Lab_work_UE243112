#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int x[1005];

bool promising(int i) {
    for (int k = 1; k < i; k++) {
        if (x[k] == x[i] || abs(x[k] - x[i]) == abs(k - i))
            return false;
    }
    return true;
}

void nQueens(int i, int n) {
    if (i > n) return;

    for (int j = 1; j <= n; j++) {
        x[i] = j;
        if (promising(i)) {
            nQueens(i + 1, n);
        }
    }
}

int main() {
    cout << "N\tTime(ms)\n";

    for (int n = 5; n <= 15; n++) {

        auto start = high_resolution_clock::now();

        nQueens(1, n);

        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);

        cout << n << "\t" << duration.count() << "\n";
    }

    return 0;
}