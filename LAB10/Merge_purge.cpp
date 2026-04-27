#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int p;   
    int w;   
};



vector<node> mergePurge(vector<node>& S, node item, int M) {
    vector<node> T;
    vector<node> U;

    
    for (auto x : S)
        T.push_back(x);

    for (auto x : S) {
        node y;
        y.p = x.p + item.p;
        y.w = x.w + item.w;

        if (y.w <= M)
            T.push_back(y);
    }

    
    sort(T.begin(), T.end(), [](node a, node b) {
        return a.w < b.w;
    });

    
    int maxProfit = -1;

    for (auto x : T) {
        if (x.p > maxProfit) {
            U.push_back(x);
            maxProfit = x.p;
        }
    }

    return U;
}

int main() {
    int n = 5;
    int M = 10;   

    int profit[5] = {10, 20, 30, 40, 50};
    int weight[5] = {1, 3, 4, 6, 7};

    vector<node> S;
    S.push_back({0, 0});   

    for (int i = 0; i < n; i++) {
        node item;
        item.p = profit[i];
        item.w = weight[i];

        S = mergePurge(S, item, M);
    }

    cout << "Final non-dominated solutions:\n";

    for (auto x : S) {
        cout << "Profit = " << x.p
             << " Weight = " << x.w << endl;
    }

    cout << "\nMaximum Profit = "
         << S.back().p << endl;

    return 0;
}