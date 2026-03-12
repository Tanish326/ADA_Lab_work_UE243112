#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

struct Edge {
    int to;
    int weight;
};


vector<int> dijkstra(int n, vector<vector<Edge>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for(auto edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;
            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    srand(time(0));

    double avgTime[200];
    int row = 0;

    for(int n = 5; n <= 1000; n += 5) {
        double totalTime = 0;

        for(int k = 0; k < 10; k++) {
        
            vector<vector<Edge>> adj(n);

            
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    if(rand() % 2) { 
                        int w = rand() % 100 + 1;
                        adj[i].push_back({j, w});
                        adj[j].push_back({i, w}); 
                    }
                }
            }

            auto start = high_resolution_clock::now();
            dijkstra(n, adj, 0);
            auto end = high_resolution_clock::now();

            double time_taken = duration<double, micro>(end - start).count();
            totalTime += time_taken;
        }

        avgTime[row] = totalTime / 10.0;
        cout << "n = " << n << "  Avg Time = " << avgTime[row] << " microseconds" << endl;
        row++;
    }

    return 0;
}