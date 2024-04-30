#include <iostream>
#include <string>
using namespace std;

#define DIR_LEN 4

int dx[DIR_LEN] = {0,1,0,-1};
int dy[DIR_LEN] = {1,0,-1,0};

int elapse_time = 0;
int ans = -1;

int main() {
    string command;
    cin >> command;

    int x = 0, y = 0;
    int dir = 3;

    for (int i = 0; i < command.length(); i++) {
        if (command[i] == 'L') {
            dir = (dir + 1) % 4;        
        } else if (command[i] == 'R') {
            dir = (dir -1 + 4) % 4;
        } else {
            x = x + dx[dir], y = y + dy[dir];
        }
        elapse_time++;
        if (x == 0 && y == 0) {
            ans = elapse_time;
            break;
        }
    }

    cout << ans;
    
    return 0;
}