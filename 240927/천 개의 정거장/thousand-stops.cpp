#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAX_N 1000
using namespace std;


void dijkstra(
              int s,
              int n,
              const vector<tuple<int, int, int>> (&graph)[MAX_N + 1],
              int (&dist)[MAX_N + 1],
              int (&path)[MAX_N + 1]
              ) {
    priority_queue<tuple<int,int,int>> pq = priority_queue<tuple<int,int, int>>();
    
    for (int i = 1; i <= n; i++) {
        dist[i]= (int)1e9;
    }
    
    dist[s] = 0;
    pq.push(make_tuple(-0, s, 0));
    
    while (!pq.empty()) {
        int min_dist, min_index, current_bus;
        tie(min_dist, min_index, current_bus) = pq.top();
        pq.pop();
        
        if (min_dist > dist[min_index])
            continue;
        
        for (int j = 0; j < graph[min_index].size(); j++) {
            int target_index, target_dist, target_bus;
            tie(target_index, target_dist, target_bus) = graph[min_index][j];
            
            int new_dist = dist[min_index];
            
            if (current_bus != target_bus) {
                new_dist += target_dist;
            }
            
            if (new_dist < dist[target_index]) {
                dist[target_index] = new_dist;
                path[target_index] = min_index;
                
                pq.push(make_tuple(-new_dist, target_index, target_bus));
            }
        }
    }
};

int main() {
    int A, B, station_cnt;
    int fee, bus_cnt;
    vector<tuple<int, int, int>> graph[MAX_N + 1];
    int dist[MAX_N + 1];
    int path[MAX_N + 1];
    
    cin >> A >> B >> station_cnt;
    
    for (int i = 1; i <= station_cnt; i++) {
        int current_station, next_station;
        
        cin >> fee >> bus_cnt;
        
        cin >> current_station;
        
        for (int j = 1; j < bus_cnt; j++) {
            cin >> next_station;
            graph[current_station].push_back(make_tuple(next_station, fee, i));
            current_station = next_station;
        }
        
    }
    
    dijkstra(A, MAX_N, graph, dist, path);
    
    if (dist[B] == (int)1e9) {
        cout << "-1 -1";
    } else {
        cout << dist[B] << " ";
        
        int x = B;
        int time = 0;
        
        while(x != A) {
            time++;
            x = path[x];
        }
        
        cout << time;
    }
    
    return 0;
}