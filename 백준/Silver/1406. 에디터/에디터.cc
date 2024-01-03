#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <list>
using namespace std;

int N, X;

int A;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<char> text;
    string str;
    cin >> str;

    for (char ch : str) {
        text.push_back(ch);
    }

    int N;
    cin >> N;
    auto t = text.end();

    for (int i = 0; i < N; i++) {
        char command;
        cin >> command;

        if (command == 'P') {
            char add;
            cin >> add;
            text.insert(t, add);
        }
        else if (command == 'L') {
            if (t != text.begin()) t--;
        }
        else if (command == 'D') {
            if (t != text.end()) t++;
        }
        else if (command == 'B') {
            if (t != text.begin()) {
                t = text.erase(--t);
            }
        }
    }

    for (char val : text) {
        cout << val;
    }

    return 0;
}
