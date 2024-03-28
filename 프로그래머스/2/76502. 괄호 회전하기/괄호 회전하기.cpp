#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <stack>

using namespace std;

deque<char>dq;

int solution(string s) {
    int answer = 0;
    for(char c : s){
        dq.push_back(c);
    }
    int cnt = 0;
    while(cnt!=s.size()){
        //올바른괄호인지 확인
        bool is_ok = true;
stack<char> q;
        q.push(dq[0]);
        for(int i =1;i<dq.size();i++){
            if(dq[i]==')'){
                if(q.size() != 0 &&q.top()=='('){
                    q.pop();
                }else{
                    q.push(dq[i]);
                }
            } else if(q.size() != 0 &&dq[i] == '}'){
                if(q.top()=='{'){
                    q.pop();
                }else{
                    q.push(dq[i]);
                }
            } else if(q.size() != 0 &&dq[i] == ']'){
                if(q.top()=='['){
                    q.pop();
                }else{
                    q.push(dq[i]);
                }
            }else{
                q.push(dq[i]);
            } 
        }
        
        // while(!q.empty()){
        //     cout << q.front() << " ";
        //     q.pop();
        // }
        // cout << "\n";
        // for(auto d : dq){
        //     cout << d;
        // }
        
        if(q.empty()) answer++;
        //cout <<"\n"<< answer;
        //왼쪽으로 돌리기
        cnt++;
        char front = dq.front();
        dq.pop_front();
        dq.push_back(front);
        
    }
    
    return answer;
}