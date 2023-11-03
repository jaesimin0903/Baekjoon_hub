#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(int N, int number) {
    int answer = -1; // 최솟값이 8보다 크면 -1을 return
    unordered_set<int> s[8]; // 정렬할 필요 X, 중복제거는 필요 - unordered_set 사용
    
    int sum = 0;
    for(int i = 0; i < 8; ++i){ // 각 항목에다가 N, NN, NNN... 넣어줌
        sum = 10*sum + N;
        s[i].insert(sum);
    }
    
    for (int i = 1; i < 8; ++i){
        for(int j = 0; j < i; ++j){
            for(int a : s[j]){
                for(int b : s[i-j-1]){
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b != 0)
                        s[i].insert(a/b);
                }
            }
        }
    }

    for(int i = 0; i < 8; ++i){
        if(s[i].find(number) != s[i].end()){
            answer = i + 1;
            break;
        }  
    }

    
    return answer;
}

//1 : 5
//2 : 5+5 5/5 5*5 5-5 10 1 25 0
//3 : 5+5+5 5+5-5