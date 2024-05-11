#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

int n, k;

void print() {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

void choose(int curr_num) {
    if (curr_num > n) {
        print();
        return;
    }

    for (int i = 1; i <= k; i++) {
        ans.push_back(i);
        choose(curr_num+1);
        ans.pop_back();
    }
}

int main() {
    cin >> k >> n;
    
    choose(1);

    return 0;
}