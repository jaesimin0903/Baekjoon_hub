#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string pattern;
    cin >> pattern;

    // 패턴을 '*'를 기준으로 왼쪽 부분과 오른쪽 부분으로 나눕니다.
    int starPos = pattern.find('*');
    string leftPattern = pattern.substr(0, starPos);
    string rightPattern = pattern.substr(starPos + 1);

    while (N--) {
        string s;
        cin >> s;
        bool match = false;

        // 문자열의 시작 부분이 leftPattern과 일치하는지,
        // 그리고 문자열의 끝 부분이 rightPattern과 일치하는지 확인합니다.
        if (s.substr(0, leftPattern.size()) == leftPattern && 
            s.size() >= leftPattern.size() + rightPattern.size() && 
            s.substr(s.size() - rightPattern.size()) == rightPattern) {
            match = true;
        }

        if (match) {
            cout << "DA" << "\n";
        } else {
            cout << "NE" << "\n";
        }
    }

    return 0;
}
