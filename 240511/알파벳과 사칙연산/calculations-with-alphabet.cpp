#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> seq;
vector<int> ans;

int ans_num = 0;

void caculate() {
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i];
    // }
    // cout << endl;
    
    int tmp = ans[0];

    if (seq.size() != 1) {
        for (int i = 2; i < seq.size(); i+=2) {
            // cout << ans[i-2] << endl;
            if (seq[i-1] == '+') {
                tmp = tmp + ans[i/2];
            } else if (seq[i-1] == '-') {
                tmp = tmp - ans[i/2];
            } else if (seq[i-1] == '*') {
                tmp = tmp * ans[i/2];
            }
        }
    }
    

//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << " ";
//    }
//    cout << endl;
    // cout << tmp << endl;

   ans_num = max(tmp, ans_num);
}

void choose(int curr_num) {
    if (curr_num == ((seq.size() -1)/2) + 2) {
        caculate();
        return;
    }
    for (int i = 1; i <=4; i++) {
        ans.push_back(i);
        choose(curr_num+1);
        ans.pop_back();
    }

}

int main() {
    string exp;
    cin >> exp;

    for (int i = 0; i < exp.size(); i++) {
        seq.push_back(exp[i]);
    }

//     for (int i = 0; i < seq.size(); i++) {
//         cout << seq[i] << " ";
//    }

    choose(1);
    
    cout << ans_num;
    
    
    return 0;
}