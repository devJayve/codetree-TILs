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
              const vector<pair<int, int>> (&graph)[MAX_N + 1],
              const int (&bus_type)[MAX_N + 1][MAX_N + 1],
              int (&dist)[MAX_N + 1],
              int (&path)[MAX_N + 1]
              ) {
    priority_queue<pair<int,int>> pq = priority_queue<pair<int,int>>();
    int current_bus = -1;
    
    for (int i = 1; i <= n; i++) {
        dist[i]= (int)1e9;
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
            
            int new_dist = dist[min_index];
            if (bus_type[min_index][target_index] != current_bus) {
                new_dist += target_dist;
            }
            
            if (new_dist < dist[target_index]) {
                dist[target_index] = new_dist;
                current_bus = bus_type[min_index][target_index];
                path[target_index] = min_index;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }
};

int main() {
    int A, B, station_cnt;
    int fee, bus_cnt;
    int max_station = -1;
    vector<pair<int, int>> graph[MAX_N + 1];
    int bus_type[MAX_N + 1][MAX_N + 1];
    int dist[MAX_N + 1];
    int path[MAX_N + 1];
    
    cin >> A >> B >> station_cnt;
    
    for (int i = 1; i <= station_cnt; i++) {
        cin >> fee >> bus_cnt;
        
        int current_station, next_station;
        cin >> current_station;
        
        max_station = max(max_station, current_station);
        
        for (int j = 1; j < bus_cnt; j++) {
            cin >> next_station;
            graph[current_station].push_back(make_pair(next_station, fee));
            bus_type[current_station][next_station] = i;
            max_station = max(max_station, next_station);
            current_station = next_station;
        }
    }
    
    dijkstra(A, max_station, graph, bus_type, dist, path);
    
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