#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

vector<vector<int>> multiplyBasic(const vector<vector<int>> &X, const vector<vector<int>> &Y) {
    int dim = X.size();
    vector<vector<int>> Z(dim, vector<int>(dim, 0));

    for(int r = 0; r < dim; r++)
        for(int c = 0; c < dim; c++)
            for(int k = 0; k < dim; k++)
                Z[r][c] += X[r][k] * Y[k][c];

    return Z;
}


vector<vector<int>> sumMatrix(const vector<vector<int>> &X, const vector<vector<int>> &Y) {
    int dim = X.size();
    vector<vector<int>> Z(dim, vector<int>(dim));

    for(int r = 0; r < dim; r++)
        for(int c = 0; c < dim; c++)
            Z[r][c] = X[r][c] + Y[r][c];

    return Z;
}

vector<vector<int>> diffMatrix(const vector<vector<int>> &X, const vector<vector<int>> &Y) {
    int dim = X.size();
    vector<vector<int>> Z(dim, vector<int>(dim));

    for(int r = 0; r < dim; r++)
        for(int c = 0; c < dim; c++)
            Z[r][c] = X[r][c] - Y[r][c];

    return Z;
}

vector<vector<int>> fastMultiply(const vector<vector<int>> &X, const vector<vector<int>> &Y) {
    int dim = X.size();

    
    if(dim <= 32) {
        return multiplyBasic(X, Y);
    }

    int half = dim / 2;
    vector<vector<int>> result(dim, vector<int>(dim));

    vector<vector<int>> X11(half, vector<int>(half)), X12(half, vector<int>(half));
    vector<vector<int>> X21(half, vector<int>(half)), X22(half, vector<int>(half));

    vector<vector<int>> Y11(half, vector<int>(half)), Y12(half, vector<int>(half));
    vector<vector<int>> Y21(half, vector<int>(half)), Y22(half, vector<int>(half));

    for(int r = 0; r < half; r++) {
        for(int c = 0; c < half; c++) {
            X11[r][c] = X[r][c];
            X12[r][c] = X[r][c + half];
            X21[r][c] = X[r + half][c];
            X22[r][c] = X[r + half][c + half];

            Y11[r][c] = Y[r][c];
            Y12[r][c] = Y[r][c + half];
            Y21[r][c] = Y[r + half][c];
            Y22[r][c] = Y[r + half][c + half];
        }
    }

    
    auto P1 = fastMultiply(sumMatrix(X11, X22), sumMatrix(Y11, Y22));
    auto P2 = fastMultiply(sumMatrix(X21, X22), Y11);
    auto P3 = fastMultiply(X11, diffMatrix(Y12, Y22));
    auto P4 = fastMultiply(X22, diffMatrix(Y21, Y11));
    auto P5 = fastMultiply(sumMatrix(X11, X12), Y22);
    auto P6 = fastMultiply(diffMatrix(X21, X11), sumMatrix(Y11, Y12));
    auto P7 = fastMultiply(diffMatrix(X12, X22), sumMatrix(Y21, Y22));

    
    auto Z11 = sumMatrix(diffMatrix(sumMatrix(P1, P4), P5), P7);
    auto Z12 = sumMatrix(P3, P5);
    auto Z21 = sumMatrix(P2, P4);
    auto Z22 = sumMatrix(diffMatrix(sumMatrix(P1, P3), P2), P6);

    
    for(int r = 0; r < half; r++) {
        for(int c = 0; c < half; c++) {
            result[r][c] = Z11[r][c];
            result[r][c + half] = Z12[r][c];
            result[r + half][c] = Z21[r][c];
            result[r + half][c + half] = Z22[r][c];
        }
    }

    return result;
}


int main() {
    vector<int> dims = {16, 32, 64, 128};
    int trials = 3;

    cout << "n\tTime (microseconds)" << endl;

    for(int dim : dims) {

        long long totalDuration = 0;

        for(int t = 0; t < trials; t++) {

            vector<vector<int>> matA(dim, vector<int>(dim));
            vector<vector<int>> matB(dim, vector<int>(dim));

            for(int r = 0; r < dim; r++)
                for(int c = 0; c < dim; c++) {
                    matA[r][c] = rand() % 10;
                    matB[r][c] = rand() % 10;
                }

            auto begin = high_resolution_clock::now();
            auto matC = fastMultiply(matA, matB);
            auto finish = high_resolution_clock::now();

            totalDuration += duration_cast<microseconds>(finish - begin).count();
        }

        cout << dim << "\t" << totalDuration / trials << endl;
    }

    return 0;
}