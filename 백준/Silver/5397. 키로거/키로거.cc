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

    

    cin >> N;
    
    while (N--) {
        string str;
        cin >> str;
        list<char> text;
        

        auto t = text.end();

        for (int i = 0; i < str.size(); i++) {
            char command = str[i];

            if (command == ' ') {

            }
            else if (command == '<') {
                if (t != text.begin()) t--;
            }
            else if (command == '>') {
                if (t != text.end()) t++;
            }
            else if (command == '-') {
                if (t != text.begin()) {
                    t = text.erase(--t);
                }
            }
            else {
                text.insert(t, command);
            }
        }

        for (char val : text) {
            cout << val;
        }
        cout << "\n";
    }
    return 0;
}
