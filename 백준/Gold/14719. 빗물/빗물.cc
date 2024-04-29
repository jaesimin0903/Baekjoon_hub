#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> heights(W);
    for (int i = 0; i < W; i++) {
        cin >> heights[i];
    }

    int answer = 0;
    for (int i = 0; i < W; i++) {
        int left_max = 0, right_max = 0;
        for (int j = 0; j < i; j++) {
            left_max = max(left_max, heights[j]);
        }
        for (int j = i + 1; j < W; j++) {
            right_max = max(right_max, heights[j]);
        }
        int water_level = min(left_max, right_max);
        if (water_level > heights[i]) {
            answer += water_level - heights[i];
        }
    }

    cout << answer << endl;
    return 0;
}
