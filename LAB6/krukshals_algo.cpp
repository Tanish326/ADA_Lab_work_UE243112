#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

struct Edge{
    int u, v, w;
};

void adjust(vector<Edge> &arr, int i, int n){
    int smallest = i;
    int left = 2*i + 1;  
    int right = 2*i + 2;

    if(left < n && arr[left].w < arr[smallest].w) smallest = left;
    if(right < n && arr[right].w < arr[smallest].w) smallest = right;

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        adjust(arr, smallest, n);
    }
}

void heapify(vector<Edge> &arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        adjust(arr, i, n);
    }
}

Edge extractMin(vector<Edge> &heap){
    Edge minEdge = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    adjust(heap, 0, heap.size());
    return minEdge;
}

int findParent(int u, vector<int> &parent){
    if(parent[u] != u)
        parent[u] = findParent(parent[u], parent);
    return parent[u];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if(pu == pv) return;

    if(rank[pu] < rank[pv]) parent[pu] = pv;
    else if(rank[pu] > rank[pv]) parent[pv] = pu;
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
}


int kruskal(vector<Edge> &edges, int n){
    vector<int> parent(n), rank(n, 0);
    for(int i=0;i<n;i++) parent[i] = i;

    heapify(edges); 

    int mstWeight = 0;
    int edgesTaken = 0;

    while(!edges.empty() && edgesTaken < n-1){
        Edge e = extractMin(edges);
        int u = e.u, v = e.v;
        if(findParent(u, parent) != findParent(v, parent)){
            mstWeight += e.w;
            unionSet(u, v, parent, rank);
            edgesTaken++;
        }
    }
    return mstWeight;
}


int main(){
    srand(time(0));

    vector<vector<double>> avgTime; 

    for(int n=5;n<=1000;n+=5){
        double totalTime = 0;

        for(int t=0;t<10;t++){
            int maxEdges = n*(n-1)/2;
            int numEdges = min(maxEdges, n*2); 
            vector<Edge> edges;

            for(int i=0;i<numEdges;i++){
                int u = rand()%n;
                int v = rand()%n;
                while(v==u) v = rand()%n;
                int w = rand()%1000 + 1;
                edges.push_back({u,v,w});
            }

            auto start = high_resolution_clock::now();
            kruskal(edges, n);
            auto end = high_resolution_clock::now();

            double time_taken = duration<double, micro>(end-start).count();
            totalTime += time_taken;
        }

        avgTime.push_back({(double)n, totalTime/10.0});
        cout<<"n = "<<n<<"  Avg Time = "<<totalTime/10.0<<" microseconds"<<endl;
    }

    
    ofstream fout("kruskal_avg_time.csv");
    fout << "n,avg_time\n";
    for(auto &row : avgTime){
        fout << row[0] << "," << row[1] << "\n";
    }
    fout.close();

    return 0;
}