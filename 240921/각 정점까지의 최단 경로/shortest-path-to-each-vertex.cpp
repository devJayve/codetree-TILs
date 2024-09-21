#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define MAX 100
using namespace std;

vector<pair<int, int>> graph[MAX + 1];
priority_queue<pair<int, int>> pq;

int dist[MAX + 1];


int main() {
    int n, m;
    int k;
    int x, y, z;
    
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }
    
    for (int i = 1; i <= n; i++)
        dist[i] = (int)1e9;
    
    dist[k] = 0;
    
    pq.push(make_pair(-0, k));
    
    while (!pq.empty()) {
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();
        
        min_dist = -min_dist;
        
        if (min_dist != dist[min_index])
            continue;
        
        for (int j = 0; j < (int)graph[min_index].size(); j++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][j];
            
            int new_dist = dist[min_index] + target_dist;
            if (dist[target_index] > new_dist) {
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if (dist[i] == (int)1e9) dist[i] = -1;
        cout << dist[i] << '\n';
    }

    return 0;
    
    
    
    
}