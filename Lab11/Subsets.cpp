#include <bits/stdc++.h>
using namespace std;

int target;
vector<int> arr;

bool checking_boundary(int i, int s, int r) {
    return (s + r >= target) && (s == target || s + arr[i] <= target);
}

void subset(int i, int s, int r, vector<int>& x) {

    if (checking_boundary(i, s, r)) {

        if (s == target) {
            for (int j = 0; j < arr.size(); j++) {
                if (x[j] == 1)
                    cout << arr[j] << " ";
            }
            cout << endl;
        }
        else if (i < arr.size()) {

        
            x[i] = 1;
            subset(i + 1, s + arr[i], r - arr[i], x);

        
            x[i] = 0;
            subset(i + 1, s, r - arr[i], x);
        }
    }
}

int main() {
    arr = {1, 2, 3, 4, 5};
    target = 5;

    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<int> x(arr.size(), 0);

    subset(0, 0, totalSum, x);
}