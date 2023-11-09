#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
        int answer = 0;

    vector<int> onRoad;
    for (int i = 0; i < bridge_length - 1; i++) {
        onRoad.push_back(0);
    }
    onRoad.push_back(truck_weights.front());
    truck_weights.erase(truck_weights.begin());
    answer++;
    while (!onRoad.empty()&&!truck_weights.empty()) {
        int onRoadW = 0;
        for (int i = 1; i < onRoad.size(); i++) {
            onRoadW += onRoad[i];
        }
        onRoadW += truck_weights.front();
        if (onRoadW > weight) {
            onRoad.push_back(0);
        }
        else {
            onRoad.push_back(truck_weights.front());
            truck_weights.erase(truck_weights.begin());
        }

        onRoad.erase(onRoad.begin());

        answer++;

    }

    if (!onRoad.empty()) {
        for (int i = onRoad.size()-1; i >0 ; i--) {
            if (onRoad[i] > 0) {
                answer += i + 1;
                break;
            }
        }
    }

    return answer;
}

//7
//70 길이 꽉안찼지만 무게가 넘을때
//04