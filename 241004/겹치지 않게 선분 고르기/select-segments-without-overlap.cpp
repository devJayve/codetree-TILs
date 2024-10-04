#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int n;
int max_line;
vector<pair<int,int>> lines;
vector<bool> line;

int count_line() {
    int line_size;
    priority_queue<pair<int,int>> pq = priority_queue<pair<int,int>>();
    
    for (int i = 0; i < lines.size(); i++) {
        if (line[i] == true) pq.push(lines[i]);
    }
    
    line_size = (int)pq.size();
    
    int x1 = 1001, x2 = 1001;
    int cur_x1, cur_x2;

    while (!pq.empty()) {
        tie(cur_x1, cur_x2) = pq.top();
        pq.pop();
        
        if (cur_x2 >= x2) return -1;
        
        x1 = cur_x1; x2 = cur_x2;
    }
    
    
    return line_size;
}

void pick_line(int cur_num) {
    if (cur_num == lines.size()) {
        max_line = max(max_line, count_line());
        return;
    }
    
    line.push_back(0);
    pick_line(cur_num + 1);
    line.pop_back();
    
    line.push_back(1);
    pick_line(cur_num + 1);
    line.pop_back();
}

int main() {
    int x1, x2;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        lines.push_back(make_pair(x1, x2));
    }
    
    pick_line(0);
    
    cout << max_line;
    
    
    return 0;
}