#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0;i<arr1.size();i++){
        vector<int> s;
        for(int k =0;k<arr2[0].size();k++){
            int sum =0;
            for(int j =0;j<arr1[i].size();j++){
                sum += arr1[i][j] * arr2[j][k];  
            }
            s.push_back(sum);
        }
        answer.push_back(s);
    }
    
    return answer;
}

// 14 33
// 32 33
// 41