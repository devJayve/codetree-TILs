#include <iostream>
#include <string>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};


int main() {
    int n;
    int dir_num = 3;
    int x =0, y = 0;
    string command_string;

    cin >> command_string;
    
    for (int i = 0; i < command_string.length(); i++) {
        char command = command_string[i];

        if (command == 'L') {
            dir_num = (dir_num - 1 + 4) % 4;
        } else if (command == 'R') {
            dir_num = (dir_num + 1) % 4;
        } else {
            x = x + dx[dir_num];
            y = y + dy[dir_num];       
        }
        
        
        
    }

    cout << x << " " << y;
    
    
    return 0;
}