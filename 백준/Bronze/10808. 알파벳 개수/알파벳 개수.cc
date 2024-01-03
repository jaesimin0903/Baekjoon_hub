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

    int arr[26];
    fill(arr, arr + 26, 0);

    string str;

    cin >> str;

    for (int i = 0;i< str.size(); i++) {
        arr[(int)(str[i] - 'a')]++;
    }
 
    for (int v : arr) {
        cout << v <<" ";
    }

    return 0;
}
