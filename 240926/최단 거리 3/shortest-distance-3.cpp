#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_N 1000
using namespace std;

void dijkstra(int s, int n, const vector<pair<int, int>> (&graph)[MAX_N + 1], int (&dist)[MAX_N + 1]) {
    priority_queue<pair<int,int>> pq = priority_queue<pair<int,int>>();
    for (int i = 1; i <= n; i++) {
        dist[i] = (int)1e9;
    }
    
    dist[s] = 0;
    pq.push(make_pair(-0, s));
    
    while (!pq.empty()) {
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();
        
        if (min_dist > dist[min_index])
            continue;
        
        for (int j = 0; j < graph[min_index].size(); j++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][j];
            
            int new_dist = dist[min_index] + target_dist;
            
            if (new_dist < dist[target_index]) {
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }
    
    
}


int main() {
    int n, m;
    int x, y, d;
    int s, t;
    vector<pair<int, int>> graph[MAX_N + 1];
    int dist[MAX_N + 1];
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
    
    cin >> s >> t;
    
    
    dijkstra(s, n, graph, dist);
    
    cout << dist[t];
    
    
    return 0;
}