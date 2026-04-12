#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    srand(time(0)); 

    cout << "Size,Time(us)\n";

    for(int V = 100; V <= 1000; V += 100){

        int runs = 10;
        long long total_time = 0;

        for(int r = 0; r < runs; r++){

            vector<vector<int>> adj(V + 1);
            vector<int> indegree(V + 1, 0);


            vector<vector<int>> stage_nodes;
            int node = 1;

            while(node <= V){
                int cnt = rand() % 3 + 1; 
                vector<int> temp;

                for(int i = 0; i < cnt && node <= V; i++){
                    temp.push_back(node++);
                }

                stage_nodes.push_back(temp);
            }

            
            for(int i = 0; i < stage_nodes.size() - 1; i++){
                for(int u : stage_nodes[i]){

                    int edges = rand() % stage_nodes[i+1].size() + 1;

            
                    vector<int> next = stage_nodes[i+1];
                    random_shuffle(next.begin(), next.end());

                    for(int j = 0; j < edges; j++){
                        int v = next[j];
                        adj[u].push_back(v);
                        indegree[v]++;
                    }
                }
            }

        
            queue<int> q;
            vector<int> stage(V + 1, 0);

            for(int i = 1; i <= V; i++){
                if(indegree[i] == 0){
                    q.push(i);
                    stage[i] = 1;
                }
            }

            auto start = high_resolution_clock::now();

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v : adj[u]){
                    stage[v] = max(stage[v], stage[u] + 1);

                    indegree[v]--;
                    if(indegree[v] == 0){
                        q.push(v);
                    }
                }
            }

            auto stop = high_resolution_clock::now();
            total_time += duration_cast<microseconds>(stop - start).count();
        }

        cout << V << "," << total_time / runs << "\n";
    }

    return 0;
}