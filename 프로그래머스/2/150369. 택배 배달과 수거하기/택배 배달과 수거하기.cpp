#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> deliveryStack, pickupStack;

    // 스택에 각 집의 배송 및 픽업 수량을 넣습니다.
    for (int i = 0; i < n; i++) {
        if (deliveries[i] > 0) deliveryStack.push(i);
        if (pickups[i] > 0) pickupStack.push(i);
    }

    while (!deliveryStack.empty() || !pickupStack.empty()) {
        int furthest = 0;

        // 가장 먼 배송 또는 픽업 지점을 찾습니다.
        if (!deliveryStack.empty()) furthest = max(furthest, deliveryStack.top());
        if (!pickupStack.empty()) furthest = max(furthest, pickupStack.top());

        answer += (furthest + 1) * 2;

        // 배송 처리
        int cur_cap = cap;
        while (!deliveryStack.empty() && cur_cap > 0) {
            int idx = deliveryStack.top();
            if (deliveries[idx] <= cur_cap) {
                cur_cap -= deliveries[idx];
                deliveries[idx] = 0;
                deliveryStack.pop();
            } else {
                deliveries[idx] -= cur_cap;
                cur_cap = 0;
            }
        }

        // 픽업 처리
        cur_cap = cap;
        while (!pickupStack.empty() && cur_cap > 0) {
            int idx = pickupStack.top();
            if (pickups[idx] <= cur_cap) {
                cur_cap -= pickups[idx];
                pickups[idx] = 0;
                pickupStack.pop();
            } else {
                pickups[idx] -= cur_cap;
                cur_cap = 0;
            }
        }
    }

    return answer;
}
