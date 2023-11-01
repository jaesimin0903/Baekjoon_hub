#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    answer+=number[0];
    
    for(int i = 1;i<number.length();i++){

        while(k>0 && !answer.empty() && answer.back() < number[i]){
            answer.pop_back();
            k--;
        }
        
        answer+=number[i];
    }
    
    if(k>0){
        answer.erase(answer.size() - k);
    }
    
    return answer;
}