#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


string generateRandomString(int n) {
    string s = "";
    for (int i = 0; i < n; i++) {
        char ch = 'A' + rand() % 26;
        s += ch;
    }
    return s;
}


int findLCS(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    srand(time(0));

    cout << "Length\tTime (microseconds)\n";

    for (int n = 5; n <= 1000; n += 50) {

        string s1 = generateRandomString(n);
        string s2 = generateRandomString(n);

        auto start = high_resolution_clock::now();

        findLCS(s1, s2);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}