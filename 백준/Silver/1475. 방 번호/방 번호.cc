#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int N, X;

int A;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[11];
    fill(arr, arr + 11, 0);

    string str;

    cin >> str;

    for (int i = 0;i< str.size(); i++) {
        if (str[i] == '9') {
            if (arr[6] < arr[9]) {
                arr[6]++;
            }
            else {
                arr[9]++;
            }
        }
        else if (str[i] == '6') {
            if (arr[9] < arr[6]) {
                arr[9]++;
            }
            else {
                arr[6]++;
            }
        }
        else arr[str[i]-'0']++;
    }
    cout << *max_element(arr, arr+10);
    

    return 0;
}
