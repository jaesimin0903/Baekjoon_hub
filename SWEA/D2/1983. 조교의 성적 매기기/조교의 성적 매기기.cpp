#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; ++tc) {
        int N, M;
        cin >> N >> M;
        
        vector<pair<int,double>> v;
        for (int i = 0; i < N; i++) {
            double sum = 0;
            double num1, num2, num3;
            cin >> num1 >> num2 >> num3;
            sum = num1 * 0.35 + num2 * 0.45 + num3 * 0.2;
            v.push_back({ i + 1,sum });
        }

        sort(v.begin(), v.end(), [](pair<int, double>& a, pair<int, double>& b) {
            return b.second <a.second; });
        
        

        int s = N / 10;
        string grade;
        for (int i = 0; i < N; i++) {
            if (v[i].first == M) {
                if (i / s == 0) {
                    grade = "A+";
                }
                else if (i / s == 1) {
                    grade = "A0";
                }
                else if (i / s == 2) {
                    grade = "A-";
                }
                else if (i / s == 3) {
                    grade = "B+";
                }
                else if (i / s == 4) {
                    grade = "B0";
                }
                else if (i / s == 5) {
                    grade = "B-";
                }
                else if (i / s == 6) {
                    grade = "C+";
                }
                else if (i / s == 7) {
                    grade = "C0";
                }
                else if (i / s == 8) {
                    grade = "C-";
                }
                else if (i / s == 9) {
                    grade = "D0";
                }
            }
        }

        cout << "#" << tc << " " << grade<< "\n";
    }

    return 0;
}
