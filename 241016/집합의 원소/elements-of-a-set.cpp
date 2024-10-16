#include <iostream>
#define MAX 100000
using namespace std;

int arr[MAX];

int find(int a) {
    if (arr[a] == a) {
        return a;
    }
    int root_a = find(arr[a]);
    arr[a] = root_a;
    return root_a;
}

void union_set(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    
    arr[root_a] = root_b;
}

int main() {
    int n, m;
    int mode, a, b;
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> mode >> a >> b;
        if (mode) { // mode = 1
            cout << (arr[a] == arr[b]) << '\n';
        } else { // mode = 0
            union_set(a, b);
        }
    }
    
    
    
    return 0;
}