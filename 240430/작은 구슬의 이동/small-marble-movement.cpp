#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MAX_LEN 50

int arr[MAX_LEN][MAX_LEN];

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int n;

bool isRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    map<char,int> d_map;
    d_map['R'] = 0;
    d_map['D'] = 1;
    d_map['L'] = 3;
    d_map['U'] = 2;

    int t;
    cin >> n >> t;

    int r,c;
    char d;

    cin >> r >> c >> d;

    r -= 1;
    c -= 1;
    int dir = d_map[d];


    while (t--) {
        int nx = r + dx[dir], ny = c +dy[dir];
        if (!isRange(nx, ny)) {
            dir = 3 - dir;
            continue;
        }
        r = r + dx[dir];
        c = c + dy[dir];
    }

    cout << r+1 << " " << c+1;




    return 0;
}