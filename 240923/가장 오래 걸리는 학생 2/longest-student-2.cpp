#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>
#define MAX_N 100000
#define MAX_DIST 1000
using namespace std;

vector<pair<int,int>> graph[MAX_N + 1];
priority_queue<pair<int, int>> pq;
int dist[MAX_N + 1];

void dijkstra(int N) {
    int min_index, min_dist;
    
    for (int i = 1; i <= N; i++) {
        dist[i] = (int)1e9;
    }
    
    dist[N] = 0;
    pq.push(make_pair(-0, N));
    
    
    while (!pq.empty()) {
        tie(min_dist, min_index) = pq.top();
        pq.pop();
        
        min_dist = -min_dist;
        
        if (dist[min_index] != min_dist) continue;
        
        for (int i = 0; i < (int)graph[min_index].size(); i++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][i];
            
            int new_dist = dist[min_index] + target_dist;
            
            if (dist[target_index] > new_dist) {
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }
}

int main() {
    int N, M;
    int max_dist = -1;
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[b].push_back(make_pair(a, d));
    }
    
    dijkstra(N);
    
    for (int i = 1; i <= N; i++)
        max_dist = max(max_dist, dist[i]);
    
    cout << max_dist;
    
    return 0;
}