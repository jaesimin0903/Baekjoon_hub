#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> us;

int solution(vector<int> nums)
{
    int answer = 0;
    
    for(auto v : nums){
        us.insert(v);
    }
    
    answer = us.size();
    if(nums.size()/2 < us.size()){
        answer = nums.size()/2;
    }
    
    return answer;
}