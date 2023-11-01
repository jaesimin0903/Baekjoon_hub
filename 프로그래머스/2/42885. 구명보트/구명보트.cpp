#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> DQ(people.size());

    sort(people.begin(), people.end());
    copy(people.begin(), people.end(), DQ.begin());

    while(!DQ.empty())
    {
        int Front = DQ.front();
        int Back = DQ.back();
        int NextLimit = limit - Back;

        DQ.pop_back();

        if(!DQ.empty())
        {
            if(NextLimit >= Front)
            {
                DQ.pop_front();
            }
        }

        ++answer;
    }

    return answer;
}