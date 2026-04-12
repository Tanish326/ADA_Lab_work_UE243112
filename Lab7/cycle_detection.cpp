#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

int find_parent(int v, vector<int>& parent){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_parent(parent[v], parent);
}

void graph_making(int u, int v, vector<vector<int>>& adj){
    adj[u].push_back(v);
}

void union_set(int u, int v, vector<int>& parent){
    int pu = find_parent(u, parent);
    int pv = find_parent(v, parent);
    if(pu != pv){
        parent[pv] = pu;
    }
}

int main(){

    vector<vector<long long>> result;

    
    for(int n = 100; n <= 10000; n += 100){   

        vector<vector<int>> adj(n);
        vector<int> parent(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        
        for(int i = 0; i < n-1; i++){
            graph_making(i, i+1, adj);
        }

        auto start = high_resolution_clock::now();

        int flag = 0;
long long total = 0;
int runs = 10;

for(int r = 0; r < runs; r++){
    auto start = high_resolution_clock::now();

    for(int i = 0; i < n; i++){
        for(int k : adj[i]){
            if(find_parent(i,parent) == find_parent(k,parent)){
                break;
            }
            union_set(i,k,parent);
        }
    }

    auto stop = high_resolution_clock::now();
    total += duration_cast<microseconds>(stop - start).count();
}

result.push_back({n, total / runs});
    }

    
    cout << "Size,Time(us)\n";
    for(auto &row : result){
        cout << row[0] << "," << row[1] << "\n";
    }

    return 0;
}