#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int max = *max_element(priorities.begin(),priorities.end());
    

    while(!priorities.empty()){
        if(priorities.front() == max){
            if(location == 0){
                answer++;
                return answer;
            }else{
                answer++;
            }
            priorities.erase(priorities.begin());
            location--;
                max = *max_element(priorities.begin(),priorities.end());
            
        }else if(priorities.front() !=max){
            if(location == 0){
                location = priorities.size()-1;
                
            }else{
                location--;
            }
            int tmp = priorities.front();
            priorities.erase(priorities.begin());
            priorities.push_back(tmp);
        }
    }
    
    return answer;
}