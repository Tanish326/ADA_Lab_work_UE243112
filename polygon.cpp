#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

struct Point {
    int x, y;
};

int distance(Point A, Point B, Point P) {
    return abs((P.y - A.y)*(B.x - A.x) - (B.y - A.y)*(P.x - A.x));
}
int side(Point A, Point B, Point P) {
    int val = (B.y - A.y)*(P.x - A.x) - (B.x - A.x)*(P.y - A.y);
    if(val>0) return 1;
    if(val<0) return -1;
    return 0;
}


void addToHull(Point hull[], int &hullSize, Point P) {
    for(int i=0;i<hullSize;i++){
        if(hull[i].x==P.x && hull[i].y==P.y) return;
    }
    hull[hullSize++] = P;
}

void quickHullRec(Point points[], int n, Point A, Point B, int s, Point hull[], int &hullSize) {
    int idx=-1, maxDist=0;
    for(int i=0;i<n;i++){
        int temp = distance(A,B,points[i]);
        if(side(A,B,points[i])==s && temp>maxDist){
            idx=i;
            maxDist=temp;
        }
    }

    if(idx==-1){
        addToHull(hull,hullSize,A);
        addToHull(hull,hullSize,B);
        return;
    }

    quickHullRec(points,n,points[idx],A,-side(points[idx],A,B),hull,hullSize);
    quickHullRec(points,n,points[idx],B,-side(points[idx],B,A),hull,hullSize);
}


void quickHull(Point points[], int n, Point hull[], int &hullSize) {
    if(n<3){
        for(int i=0;i<n;i++) hull[hullSize++]=points[i];
        return;
    }

    int minX=0,maxX=0;
    for(int i=1;i<n;i++){
        if(points[i].x<points[minX].x) minX=i;
        if(points[i].x>points[maxX].x) maxX=i;
    }

    Point A = points[minX];
    Point B = points[maxX];

    quickHullRec(points,n,A,B,1,hull,hullSize);
    quickHullRec(points,n,A,B,-1,hull,hullSize);
}

int main() {
    const int step = 1000;
    const int maxSize = 10000;
    const int runs = 10;

    long long results[maxSize/step][2]; 

    srand(time(0));

    for(int n=step, idx=0; n<=maxSize; n+=step, idx++){
        long long totalTime = 0;

        for(int r=0;r<runs;r++){
            Point* points = new Point[n];
            for(int i=0;i<n;i++){
                points[i].x = rand()%10000;
                points[i].y = rand()%10000;
            }

            Point* hull = new Point[n*2]; 
            int hullSize = 0;

            auto start = high_resolution_clock::now();
            quickHull(points,n,hull,hullSize);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop-start);
            totalTime += duration.count();

            delete[] points;
            delete[] hull;
        }

        long long avgTime = totalTime / runs;
        results[idx][0] = n;
        results[idx][1] = avgTime;
    }

    cout << "Size\tAverage Time (microseconds)\n";
    for(int i=0;i<maxSize/step;i++){
        cout << results[i][0] << "\t" << results[i][1] << endl;
    }

    return 0;
}