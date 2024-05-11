#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;
int k, n;


void print() {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " "; 
    }
    cout << endl;
}

void choose(int curr_num) {
    if (curr_num == n+1) {
        print();
        return;
    }

    for (int i = 1; i <= k; i++) {
        answer.push_back(i);
        choose(curr_num+1);
        answer.pop_back();
    }
}

int main() {
    cin >> k >> n;

    choose(1);

    return 0;
}