#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<double> arr;
    arr.push_back(k);
    
    while (k > 1) {
        if (k % 2 == 0) {
            k /= 2;
        } else {
            k = k * 3 + 1;
        }
        arr.push_back(static_cast<double>(k));
    }
    
    vector<double> prefix_sum;
    prefix_sum.push_back(0.0);
    for (int i = 1; i < arr.size(); ++i) {
        double sum = (arr[i] + arr[i - 1]) / 2;
        prefix_sum.push_back(prefix_sum.back() + sum);
    }
    
    for (auto &range : ranges) {
        int start = range[0];
        int end = prefix_sum.size() - 1 + range[1];
        
        if (end < start) {
            answer.push_back(-1);
        } else {
            double result = prefix_sum[end] - prefix_sum[start];
            answer.push_back(result);
        }
    }
    
    return answer;
}