#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10
using namespace std;

string A;

string shift(int cnt) {
    string shiftedStr;
    
    for (int i = 0; i < A.size(); i++) {
        shiftedStr += A[(A.size()-cnt+i)%A.size()];
    }
    
    return shiftedStr;
}

int encode(string str) {
    string encodedStr = "";
    
    char charArr[MAX];
    int cntArr[MAX] = {0,};
    int idx = 0;
    charArr[idx] = str[0];
    cntArr[idx]++;
    
    for (int i = 1; i < str.size(); i++) {
        if (str[i] != str[i-1]) idx++;
        
        charArr[idx] = str[i];
        cntArr[idx]++;
    }
    
    for (int i = 0; i < idx+1; i++) {
        encodedStr += charArr[i];
        encodedStr += to_string(cntArr[i]);
    }
    
    return encodedStr.size();
}

int main() {
    int minLen = MAX;
    cin >> A;
    
    
    for (int i = 0; i < A.size(); i++) {
        string tmp = shift(i);
        int len = encode(tmp);
        minLen = min(len, minLen);
    }
    
    cout << minLen;
    
    return 0;
}