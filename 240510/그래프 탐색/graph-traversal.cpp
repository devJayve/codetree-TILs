#include <iostream>
#include <vector>
using namespace std;

#define MAX_LEN 1000

int graph[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN];
int start_points[MAX_LEN];
int end_points[MAX_LEN];

int n, m;

int cnt = 0;

void DFS(int vertex) {
    for (int curr_v = 1; curr_v <= n; curr_v++) {
        if (graph[vertex][curr_v] && !visited[curr_v]) {
            visited[curr_v] = true;
            cnt++;
            DFS(curr_v);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> start_points[i] >> end_points[i];
        int start = start_points[i];
        int end = end_points[i];
        
        graph[start][end] = 1;
        graph[end][start] = 1;
    }
    
    int root_vertex = 1;
    visited[root_vertex] = true;
    
    DFS(root_vertex);
    
    cout << cnt;
    
    return 0;
}