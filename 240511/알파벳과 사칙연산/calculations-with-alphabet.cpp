#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> num_v;

int alpha_memo[220];

string input;

int ans = -10000000;

void caculate() {
    char tmp_oper = 'A';
    int tmp_num = num_v[0];
    int num_iter = 1;

    for (int i = 1; i < input.size(); i++) {
        if (i % 2) {
            tmp_oper = input[i];
        }
        else {
            if (tmp_oper == '-') {
                tmp_num -= num_v[num_iter];    
            }
            else if (tmp_oper == '+') {
                tmp_num += num_v[num_iter];    
            }
            else if (tmp_oper == '*') {
                tmp_num *= num_v[num_iter];    
            }
            num_iter++;
        }
    }

    ans = max(ans, tmp_num);   
}

void backTracking(int curr_num) {
    if (curr_num == input.size()) {
        caculate();
        return;
    }

    if (curr_num % 2) { // operator
        backTracking(curr_num+1);
    } else { // number
        if (alpha_memo[input[curr_num]] == 0) {
            
            for (int i = 1; i <= 4; i++) {
                alpha_memo[input[curr_num]] = i;
                num_v.push_back(i);

                backTracking(curr_num+1);

                alpha_memo[input[curr_num]] = 0;
                num_v.pop_back();
            }
        } else {
            num_v.push_back(alpha_memo[input[curr_num]]);
            
            backTracking(curr_num + 1);

            num_v.pop_back();
        }
    }
}



int main() {
    cin >> input;

    for (int i = 'a' - '0'; i < 'g'- '0'; i++) {
        alpha_memo[i] = 0;
    }

    backTracking(0);

    cout << ans;
    return 0;
}