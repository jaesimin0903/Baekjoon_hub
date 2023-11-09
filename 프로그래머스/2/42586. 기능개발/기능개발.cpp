#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void print(vector<int>v){
    for(auto&val : v){
        cout << val << " ";
    }
    cout << "\n";
}


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while(!progresses.empty()){
        int idx = ceil((100.0f- progresses.front())/speeds.front());
        int count = 0;
        bool breakFlag  = false;
        for(int i =0;i<progresses.size();i++){
            progresses[i] += speeds[i] * idx;
            if(progresses[i]>=100 && !breakFlag){
                count++;
            }
            else{
                breakFlag = true;
            }
        }
       
                answer.push_back(count);
        
        for(int i = 0;i<count;i++){

            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }
        
    }
    
    return answer;
}