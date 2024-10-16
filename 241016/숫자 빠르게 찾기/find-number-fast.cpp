#include <iostream>
#define MAX 100000
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int tree[MAX];
    
    for (int i = 1; i <= n; i++) {
        cin >> tree[i];
    }
    
    for (int i = 0; i < m; i++) {
        int target;
        int left = 1, right = n;
        int idx = -1;
        
        cin >> target;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (target == tree[mid]) {
                idx = mid;
                break;
            }
            
            if (target > tree[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        cout << idx << '\n';
    }
    
    
    return 0;
}