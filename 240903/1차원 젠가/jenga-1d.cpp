#include <iostream>
#define MAX 100
using namespace std;

int arr[MAX];
int tmp[MAX];
int n;
int blockCnt;

void deleteBlock(int s, int e) {
    int cnt = 1;
    
    for (int i = 1; i <= n; i++) {
        if (i >= s && i <= e) {
            blockCnt--;
            continue;
        };
        
        tmp[cnt] = arr[i];
        cnt++;
    }
    
    for (int i = 1; i <= n; i++) {
        arr[i] = tmp[i];
    }
}

void printBlock() {
    cout << blockCnt << endl;
    for (int i = 1; i <= blockCnt; i++)
        cout << arr[i] << endl;
}

int main() {
    int s1, e1, s2, e2;
    
    cin >> n;
    blockCnt = n;
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    cin >> s1 >> e1 >> s2 >> e2;
    
    
    deleteBlock(s1, e1);
    deleteBlock(s2, e2);
    
    printBlock();
    
    return 0;
}