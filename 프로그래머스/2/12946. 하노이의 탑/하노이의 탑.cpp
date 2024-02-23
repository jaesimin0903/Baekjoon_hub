#include <string>
#include <vector>

using namespace std;
    vector<vector<int>> answer;

void hanoi (int a, int b, int num){
    if(num == 1){
        vector<int> part;
        part.push_back(a);
    part.push_back(b);
    answer.push_back(part);
        return;
    }
    
    hanoi(a, 6-a-b, num -1);
    vector<int> part;
    part.push_back(a);
    part.push_back(b);
    answer.push_back(part);
    
    hanoi(6-a-b, b, num -1);
}

vector<vector<int>> solution(int n) {
    
    hanoi(1,3,n);
    
    return answer;
}