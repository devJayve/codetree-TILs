#include <iostream>
#include <vector>
#include <tuple>
#define MAX_N 20
using namespace std;

int matrix[MAX_N + 1][MAX_N + 1];
bool is_bomb[MAX_N + 1][MAX_N + 1];

vector<pair<int,int>> bomb_loc;
vector<int> bomb_num;
int n;
int max_cnt;

int bomb_x_dir[3][4] = {
    {-2, -1, 1, 2},
    {-1, 0, 1, 0},
    {-1, -1, 1, 1},
};

int bomb_y_dir[3][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, -1},
    {-1, 1, 1, -1},
};

bool isInRange(int x, int y) {
    return ((x >= 1 || x <= n) && (y >= 1 || y <= n));
}

void countBomb() {
    int ans = 0;

    for (int i = 0; i < (int)bomb_loc.size(); i++) {
        int x,y;
        int cur_x, cur_y;
        
        tie(x, y) = bomb_loc[i];
        is_bomb[x][y] = true;
        
        for (int j = 0; j < 4; j++) {
            cur_x = x + bomb_x_dir[bomb_num[i]][j];
            cur_y = y + bomb_y_dir[bomb_num[i]][j];
            
            if (isInRange(cur_x, cur_y)) {
                is_bomb[cur_x][cur_y] = true;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (is_bomb[i][j] == true) ans++;
            is_bomb[i][j] = false;
        }
    }
    
    max_cnt = max(max_cnt, ans);
}

void makeBomb(int cur_bomb) {
    if (cur_bomb == bomb_loc.size()) {
        countBomb();
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        bomb_num.push_back(i);
        makeBomb(cur_bomb + 1);
        bomb_num.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) bomb_loc.push_back(make_pair(i,j));
        }
    }
    
    makeBomb(0);
    
    cout << max_cnt;
    
    return 0;
}