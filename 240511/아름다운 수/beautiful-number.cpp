#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;

int n;

int cnt = 0;

// 333
// 122
// 221
// 111
void print() {
    int tmp = answer[0];
    int tmp_count = 1;

    for (int i = 0; i < answer.size() -1; i++) {
        if (answer[i] == answer[i+1]) {
            tmp_count++;
            if (i == answer.size() - 2 && tmp_count % tmp != 0) {
                return;
            }
        } else {
            if (tmp_count % tmp != 0) {
                return;
            }
            tmp = answer[i+1];
            tmp_count = 1;
            if (i == answer.size() - 2 && tmp_count % tmp != 0) {
                return;
            }
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout <<  answer[i] << " ";
    }
    cout << endl;

    cnt++;
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

    if (n == 1) {
        cnt++;
    } else {
        choose(1);
    }

    cout << cnt;
    
    return 0;
}