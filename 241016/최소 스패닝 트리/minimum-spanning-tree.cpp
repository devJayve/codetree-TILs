#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define MAX_N 10000
using namespace std;

int uf[MAX_N];

int find(int x) {
    if (uf[x] == x) {
        return x;
    }
    int root_node = find(uf[x]);
    uf[x] = root_node;
    return root_node;
}


void union_node(int x, int y) {
    int X = find(x);
    int Y = find(y);
    
    uf[X] = Y;
}

int kruskal(priority_queue<tuple<int,int,int>> &edges, int N) {
    int total_weight = 0;
    
    while (!edges.empty()) {
        int weight, x, y;
        tie(weight, x, y) = edges.top();
        edges.pop();
        
        if (find(x) != find(y)) {
            total_weight += -weight;
            union_node(x, y);
        }
    }
    
    return total_weight;
}

int main() {
    int n, m;
    int x, y, w;
    priority_queue<tuple<int,int,int>> edges = priority_queue<tuple<int,int,int>>();
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        edges.push(make_tuple(-w, x, y));
    }
    
    int ans = kruskal(edges, n);
    cout << ans << '\n';
    
    
    
    return 0;
}