#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;

int n;

int cnt = 0;

bool isBeautiful() {
    for (int i = 0; i < n; i += answer[i]) {
        if (i + answer[i] - 1 >= n) {
            return false;
        }
        
        for (int j = i; j < answer[i] + i; j++) {
            if (answer[i] != answer[j]) {
                return false;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << answer[i] << " ";
    // }
    // cout << endl;
    return true;

}
void print() {
    if (isBeautiful()) {
        cnt++;
    }
}

void choose(int curr_num) {
    if (curr_num == n+1) {
        print();
        return;
    }
    
    for (int i = 1; i <= 4; i++) {
        answer.push_back(i);
        choose(curr_num+1);
        answer.pop_back();
    }
}
int main() {

    cin >> n;

    choose(1);
    
    cout << cnt;
    
    return 0;
}