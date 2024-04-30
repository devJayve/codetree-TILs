#include <iostream>
#include <string>
using namespace std;

int dx[4] = {1,0,-1,0}; // 동,남,서,북
int dy[4] = {0,-1,0,1};

int changeDirectionNumber(string value) {
    if (value == "E") {
        return 0;
    } else if (value == "S") {
        return 1;
    } else if (value == "W") {
        return 2;
    } else if (value == "N") {
        return 3;
    }
    return -1;
}

void move(int* x, int* y, int direction) {
    *x = 
    *x,*y = *x + dx[direction], *y + dy[direction];
    cout << *x << " " << *y << endl;
}

int main() {
    int N;
    int x,y = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string direction;
        int quantity;

        cin >> direction >> quantity;

        int dir = changeDirectionNumber(direction);

        x = x + (dx[dir] * quantity),y = y + (dy[dir] * quantity);
    }

    cout << x << " " << y;


    return 0;
}