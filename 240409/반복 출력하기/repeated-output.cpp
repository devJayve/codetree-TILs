#include <iostream>
using namespace std;

void printNLines(int n) {
    for (int i = 0; i < n; i++) {
        cout << "12345^&*()_";
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    printNLines(N);

    return 0;
}