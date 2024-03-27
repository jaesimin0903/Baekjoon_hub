#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;

priority_queue<int, vector<int>,greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(auto v : scoville){
        pq.push(v);
    }
    
    while(!pq.empty()){
        if(pq.top() >=K){
            return answer;
        }
        if(pq.empty()) return -1;
        int a = pq.top();
        pq.pop();
        if(pq.empty()) return -1;
        int b = pq.top();
        pq.pop();
        
        int mix = a + b*2;
        pq.push(mix);
        answer++;
    }
    
    return -1;
}