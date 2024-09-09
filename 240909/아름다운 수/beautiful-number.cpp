#include <iostream>
#include <vector>
using namespace std;

int n;
int beautiful_num_cnt = 0;
vector<int> num;

void checkIsBeautiful() {
    int continuous_cnt = 1;
    
    for (int i = 1; i < n; i++) {
        if (num.at(i) != num.at(i-1)) {
            if (continuous_cnt % num.at(i-1) != 0) return;
            continuous_cnt = 0;
        }
        continuous_cnt++;
    }
    
    if (continuous_cnt % num.back() != 0) return;
    
    beautiful_num_cnt++;
}

void chooseBeautifulNum(int curr_num) {
    if (curr_num > n) {
        checkIsBeautiful();
        return;
    }
    
    for (int i = 1; i <= 4; i++) {
        num.push_back(i);
        chooseBeautifulNum(curr_num+1);
        num.pop_back();
    }
}

int main() {
    cin >> n;
    
    chooseBeautifulNum(1);
    
    cout << beautiful_num_cnt;
    
    return 0;
}