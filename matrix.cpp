#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
using namespace std;
using namespace chrono;


void multiply(int **A, int **B, int **C, int n) {
    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    
    int **A11 = new int*[newSize]; int **A12 = new int*[newSize];
    int **A21 = new int*[newSize]; int **A22 = new int*[newSize];
    int **B11 = new int*[newSize]; int **B12 = new int*[newSize];
    int **B21 = new int*[newSize]; int **B22 = new int*[newSize];
    int **C11 = new int*[newSize]; int **C12 = new int*[newSize];
    int **C21 = new int*[newSize]; int **C22 = new int*[newSize];

    for(int i = 0; i < newSize; i++){
        A11[i]=new int[newSize]; A12[i]=new int[newSize];
        A21[i]=new int[newSize]; A22[i]=new int[newSize];
        B11[i]=new int[newSize]; B12[i]=new int[newSize];
        B21[i]=new int[newSize]; B22[i]=new int[newSize];
        C11[i]=new int[newSize]; C12[i]=new int[newSize];
        C21[i]=new int[newSize]; C22[i]=new int[newSize];
    }

    
    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+newSize];
            A21[i][j] = A[i+newSize][j];
            A22[i][j] = A[i+newSize][j+newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+newSize];
            B21[i][j] = B[i+newSize][j];
            B22[i][j] = B[i+newSize][j+newSize];
        }
    }


    int **M1 = new int*[newSize]; int **M2 = new int*[newSize];
    int **M3 = new int*[newSize]; int **M4 = new int*[newSize];
    int **M5 = new int*[newSize]; int **M6 = new int*[newSize];
    int **M7 = new int*[newSize]; int **M8 = new int*[newSize];

    for(int i = 0; i < newSize; i++){
        M1[i]=new int[newSize]; M2[i]=new int[newSize];
        M3[i]=new int[newSize]; M4[i]=new int[newSize];
        M5[i]=new int[newSize]; M6[i]=new int[newSize];
        M7[i]=new int[newSize]; M8[i]=new int[newSize];
    }

    
    multiply(A11,B11,M1,newSize); multiply(A12,B21,M2,newSize);
    multiply(A11,B12,M3,newSize); multiply(A12,B22,M4,newSize);
    multiply(A21,B11,M5,newSize); multiply(A22,B21,M6,newSize);
    multiply(A21,B12,M7,newSize); multiply(A22,B22,M8,newSize);


    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            C11[i][j] = M1[i][j] + M2[i][j];
            C12[i][j] = M3[i][j] + M4[i][j];
            C21[i][j] = M5[i][j] + M6[i][j];
            C22[i][j] = M7[i][j] + M8[i][j];
        }
    }

    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            C[i][j] = C11[i][j];
            C[i][j+newSize] = C12[i][j];
            C[i+newSize][j] = C21[i][j];
            C[i+newSize][j+newSize] = C22[i][j];
        }
    }

    
    for(int i = 0; i < newSize; i++){
        delete[] A11[i]; delete[] A12[i]; delete[] A21[i]; delete[] A22[i];
        delete[] B11[i]; delete[] B12[i]; delete[] B21[i]; delete[] B22[i];
        delete[] C11[i]; delete[] C12[i]; delete[] C21[i]; delete[] C22[i];
        delete[] M1[i]; delete[] M2[i]; delete[] M3[i]; delete[] M4[i];
        delete[] M5[i]; delete[] M6[i]; delete[] M7[i]; delete[] M8[i];
    }

    delete[] A11; delete[] A12; delete[] A21; delete[] A22;
    delete[] B11; delete[] B12; delete[] B21; delete[] B22;
    delete[] C11; delete[] C12; delete[] C21; delete[] C22;
    delete[] M1; delete[] M2; delete[] M3; delete[] M4;
    delete[] M5; delete[] M6; delete[] M7; delete[] M8;
}

int main() {
    vector<int> sizes = {16, 32, 64, 128}; 
    int runs = 3;

    cout << "n\tTime (microseconds)" << endl;

    for(int n : sizes) {

        long long totalTime = 0;

        for(int r = 0; r < runs; r++) {

            int **A = new int*[n];
            int **B = new int*[n];
            int **C = new int*[n];

            for(int i = 0; i < n; i++){
                A[i] = new int[n];
                B[i] = new int[n];
                C[i] = new int[n];

                for(int j = 0; j < n; j++){
                    A[i][j] = rand() % 10;
                    B[i][j] = rand() % 10;
                }
            }

            auto start = high_resolution_clock::now();
            multiply(A, B, C, n);
            auto stop = high_resolution_clock::now();

            totalTime += duration_cast<microseconds>(stop - start).count();

            for(int i = 0; i < n; i++){
                delete[] A[i]; delete[] B[i]; delete[] C[i];
            }
            delete[] A; delete[] B; delete[] C;
        }

        cout << n << "\t" << totalTime / runs << endl;
    }

    return 0;
}