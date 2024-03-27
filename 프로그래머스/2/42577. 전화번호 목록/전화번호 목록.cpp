#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> v;
unordered_set<string> us;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; ++i) {
        // 다음 번호가 현재 번호로 시작하는지 확인
        if(phone_book[i+1].find(phone_book[i]) == 0) {
            return false;
        }
    }
    return true;
}