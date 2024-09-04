#include <iostream>
#define MAX 100
using namespace std;

int N, M; // 폭탄의 개수, 터지는 조건 개수
int arr[MAX];
int tmp[MAX];
int total_bomb_cnt;
bool isExplosion = false;

void removeExplosion() {
    isExplosion = false;
    int bomb_cnt = 1;
    int tmp_idx = 0;
    
    for (int i = 1; i < total_bomb_cnt; i++) {
        if (arr[i] != arr[i-1]) {
            if (bomb_cnt < M) {
                tmp[tmp_idx++] = arr[i-1];
            } else {
                isExplosion = true;
            }
            bomb_cnt = 1;
        } else {
            bomb_cnt++;
        }
    }
    
    // 마지막 인덱스 확인
    if (bomb_cnt < M) tmp[tmp_idx++] = arr[N-1];
    
    for (int i = 0; i < tmp_idx; i++) {
        arr[i] = tmp[i];
    }
    
    total_bomb_cnt = tmp_idx;
    
    if (isExplosion) removeExplosion();
}


int main() {
    cin >> N >> M;
    total_bomb_cnt = N;
    
    for (int i = 0; i < N; i++)
        cin >>arr[i];
    
    removeExplosion();
    
    cout << total_bomb_cnt << endl;
    for (int i = 0; i < total_bomb_cnt; i++) {
        cout << arr[i] << endl;
    }
    
    
    
    return 0;
}