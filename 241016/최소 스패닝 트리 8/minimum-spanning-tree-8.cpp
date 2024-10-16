#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#define MAX_N 500
using namespace std;

void prim(vector<pair<int,int>> (&graph)[MAX_N],
          int (&dist)[MAX_N],
          priority_queue<pair<int,int>> &pq,
          int N
          ) {
    
    for (int i = 1; i <= N; i++) {
        dist[i] = (int)1e9;
    }
    
    dist[pq.top().second] = 0;
    
    while (!pq.empty()) {
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();
        
        for (int i = 0; i < graph[min_index].size(); i++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][i];
            
            if (target_dist < dist[target_index]) {
                dist[target_index] = target_dist;
            }
        }
    }
}

int main() {
    int n, m;
    int x, y, w;
    
    priority_queue<pair<int,int>> pq = priority_queue<pair<int,int>>();
    vector<pair<int,int>> graph[MAX_N];
    int dist[MAX_N];
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
        
        pq.push(make_pair(-w, x));
        pq.push(make_pair(-w, y));
    }
    
    prim(graph, dist, pq, n);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {

        ans += dist[i];
    }
    
    cout << ans;
    
}