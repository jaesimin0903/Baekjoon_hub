#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long cal(long long a, long long b, char c) {
    if (c == '-') return a - b;
    else if (c == '+') return a + b;
    return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;// expression에서 숫자만 뽑아낸 벡터
    vector<char> operators;// expression에서 연산자만 뽑아낸 벡터
    vector<char> oper = {'+','-','*'};
    sort(oper.begin(), oper.end());// 온전한 3! 가지수의 순열 조합을 뽑기위해서 정렬해준다.
    string tmp = "";
    for (int i=0; i<expression.size(); i++) {
        if (isdigit(expression[i])) {
            tmp += expression[i];
        } else {
            nums.push_back(stoll(tmp));
            operators.push_back(expression[i]);
            tmp = "";
        }
    }
    nums.push_back(stoll(tmp));
    
    do {
        vector<long long> numsTmp(nums);
        vector<char> operTmp(operators);
        for (int i=0; i<3; i++) {
            for (int j=0; j<operTmp.size(); ) {
                if (oper[i] == operTmp[j]) {// 순열에서의 연산자이면
                    long long res = cal(numsTmp[j], numsTmp[j+1], operTmp[j]);// 결과 숫자 계산
                    numsTmp.erase(numsTmp.begin() + j, numsTmp.begin() + j + 2);// 숫자 두개 삭제
                    operTmp.erase(operTmp.begin() + j);// 연산자 삭제
                    numsTmp.insert(numsTmp.begin() + j, res);// 결과 숫자 추가
                } else {
                    j++;
                }
            }
        }
        answer = max(answer, abs(numsTmp[0]));
    } while (next_permutation(oper.begin(), oper.end()));
    
    return answer;
}