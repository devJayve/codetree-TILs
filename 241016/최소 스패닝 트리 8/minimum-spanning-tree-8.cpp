#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#define MAX_N 500
using namespace std;

bool visited[MAX_N];

void prim(vector<pair<int,int>> (&graph)[MAX_N + 1],
          int (&dist)[MAX_N + 1],
          int N
          ) {
    priority_queue<pair<int,int>> pq = priority_queue<pair<int,int>>();
    
    for (int i = 1; i <= N; i++) {
        dist[i] = (int)1e9;
    }
    
    pq.push(make_pair(-0, 1));
    dist[1] = 0;
    
    while (!pq.empty()) {
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();
        
        // if (visited[min_index]) continue;
        
        visited[min_index] = true;
        
        for (int i = 0; i < graph[min_index].size(); i++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][i];
            
            if (target_dist < dist[target_index]) {
                dist[target_index] = target_dist;
                pq.push(make_pair(-target_dist, target_index));
            }
        }
    }
}

int main() {
    int n, m;
    int x, y, w;
    
    priority_queue<pair<int,int>> pq = priority_queue<pair<int,int>>();
    vector<pair<int,int>> graph[MAX_N + 1];
    int dist[MAX_N + 1];
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }
    
    prim(graph, dist, n);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dist[i];
    }
    
    cout << ans;
    
}