#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#define MAX_N 1000
using namespace std;

void dijkstra(int s, int n, const vector<pair<int,int>> (&graph)[MAX_N + 1], int (&dist)[MAX_N + 1]) {
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
        
        min_dist = -min_dist;
        
        if (dist[min_index] != min_dist)
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

int getMinimumByDict(int x, int n, const vector<pair<int,int>> (&graph)[MAX_N + 1], const int (&dist)[MAX_N+1]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[i][j];
            
            if (target_index != x) continue;
            
            if ((dist[i] + target_dist) == dist[target_index]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    int a, b, d;
    int s, t;
    
    cin >> n >> m;
    
    vector<pair<int,int>> graph[MAX_N + 1];
    vector<pair<int,int>> transpose_graph[MAX_N + 1];
    
    int dist[MAX_N + 1];
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        graph[a].push_back(make_pair(b, d));
        graph[b].push_back(make_pair(a, d));
    }
    
    cin >> s >> t;
    
    dijkstra(t, n, graph, dist);
    
    cout << dist[s] << '\n';
    
    
    int x = s;
    cout << x << " ";
    
    while (x != t) {
        x = getMinimumByDict(x, n, graph, dist);
        cout << x << " ";
    }
    

    
    
    return 0;
}