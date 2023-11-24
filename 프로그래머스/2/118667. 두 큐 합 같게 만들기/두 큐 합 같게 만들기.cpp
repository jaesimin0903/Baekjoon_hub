#include <string>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long q1Sum = 0;
    long long q2Sum = 0;
    long long goal = 0;
    deque<int> q1{queue1.begin(),queue1.end()};
    deque<int> q2{queue2.begin(),queue2.end()};
    for(int i = 0;i<queue1.size();i++){
        q1Sum += queue1[i];
    }
    for(int i = 0;i<queue2.size();i++){
        q2Sum += queue2[i];
    }
    
    goal = q1Sum + q2Sum;
    if(goal%(long long)2 == 1){
        return -1;
    }else{
        goal /= (long long)2;
    }
    int limit = queue1.size() * 4;
    while(answer!=limit){
        if(q1Sum > q2Sum){
            if(!q1.empty()){
                int tmp = q1.front();
                q1.pop_front();
                q1Sum -= tmp;
                q2.push_back(tmp);
                q2Sum += tmp;
                answer++;    
            }
        }else if(q1Sum < q2Sum){
            if(!q2.empty()){
                int tmp = q2.front();
                q2.pop_front();
                q2Sum -= tmp;
                q1.push_back(tmp);
                q1Sum += tmp;
                answer++;                
            }
        }else {
            return answer;
        }
        if(q1Sum == goal && q2Sum == goal){
            break;
        }
        if(answer == limit){
            return -1;
        }
    }
    return answer;
}