#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int n;
int max_line;
vector<pair<int,int>> lines;
vector<bool> line;

int checkIsNotInterrupt() {
    int line_size;
    priority_queue<pair<int,int>> pq = priority_queue<pair<int,int>>();
    
    for (int i = 0; i < lines.size(); i++) {
        if (line[i] == true) pq.push(lines[i]);
    }
    
    line_size = (int)pq.size();
    
    int x = 1001, y = 1001;
    int cur_x, cur_y;

    while (!pq.empty()) {
        tie(cur_x, cur_y) = pq.top();
        pq.pop();
        
        
        if (cur_x == x || cur_y >= y) return -1;
        
        x = cur_x; y = cur_y;
    }
    
    
    return line_size;
}

void pick(int cur_num) {
    if (cur_num == lines.size()) {
        max_line = max(max_line, checkIsNotInterrupt());
        return;
    }
    
    line.push_back(0);
    pick(cur_num + 1);
    line.pop_back();
    
    line.push_back(1);
    pick(cur_num + 1);
    line.pop_back();
}

int main() {
    int x, y;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        lines.push_back(make_pair(x, y));
    }
    
    pick(0);
    
    cout << max_line;
    
    
    return 0;
}