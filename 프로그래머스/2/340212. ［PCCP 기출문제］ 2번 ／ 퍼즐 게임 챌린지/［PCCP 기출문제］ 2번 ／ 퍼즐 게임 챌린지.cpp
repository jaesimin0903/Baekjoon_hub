#include <string>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int left = 1, right = 1e5;  // Assuming the maximum possible level can be up to 1,000,000
    //long long ans = 999999999999;
    
    while (left <= right) {
        int level = left + (right - left) / 2;
        long long sum = 0;
        
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] > level) { // Failed puzzle
                int gap = diffs[i] - level;
                if (i == 0) {
                    sum += (times[i] + 1) * gap + times[i];
                } else {
                    sum += (times[i] + times[i - 1]) * gap + times[i];
                }
            } else { // Success puzzle
                sum += times[i];
            }
            
            // If sum exceeds the limit, break early
            if (sum > limit) break;
        }
        //cout << sum << " " << level << "\n";
        if (sum <= limit) {
            answer = level;
            right = level - 1;  // Try for a higher level
        } else {
            left = level + 1; // Try for a lower level
        }
    }
    
    return answer;
}
