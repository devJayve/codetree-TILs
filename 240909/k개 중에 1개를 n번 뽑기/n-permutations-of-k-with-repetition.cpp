#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> num;

void print() {
    for (int i = 0; i < N; i++) {
        cout << num.at(i) << " ";
    }
    cout << '\n';
}

void pick(int n) {
    if (n > N) {
        print();
        return;
    }
    
    for (int i = 1; i <= K; i++) {
        num.push_back(i);
        pick(n+1);
        num.pop_back();
    }
}

int main() {
    cin >> K >> N;
    
    pick(1);
    
    
    return 0;
}