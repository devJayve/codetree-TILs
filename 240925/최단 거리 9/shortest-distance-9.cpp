#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_N 1000
using namespace std;


void dijkstra(int s, int t, int n, const vector<pair<int,int>> (&graph)[MAX_N + 1], int (&dist)[MAX_N + 1], int (&path)[MAX_N + 1]) {
    priority_queue<pair<int, int>> pq = priority_queue<pair<int,int>>();
    
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
        
        if (dist[min_index] > min_dist)
            continue;
        
        for (int i = 0; i < graph[min_index].size(); i++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][i];
            
            int new_dist = dist[min_index] + target_dist;
            
            if (dist[target_index] > new_dist) {
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
                
                path[target_index] = min_index;
            }
        }
    }
}

int main() {
    int n, m;
    int a, b, d;
    int s, t;
    cin >> n >> m;
    
    vector<pair<int,int>> graph[MAX_N + 1];
    int dist[MAX_N + 1];
    int path[MAX_N + 1];
    
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        
        graph[a].push_back(make_pair(b, d));
        graph[b].push_back(make_pair(a, d));
    }
    
    cin >> s >> t;
    
    dijkstra(s, t, n, graph, dist, path);
    
    cout << dist[t] << '\n';
    
    int x = 5;
    vector<int> vertices;
    vertices.push_back(x);
    
    while (x != 1) {
        vertices.push_back(path[x]);
        x = path[x];
    }
    
    for (int i = (int)vertices.size() - 1; i >= 0; i--) {
        cout << vertices[i] << " ";
    }
    
    return 0;
}