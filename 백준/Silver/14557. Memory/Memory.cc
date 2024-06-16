
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    int kind = (R * C) / 2;
    int min_val = kind;
    int max_val = (R * C)-1;
    

    cout << min_val << ' ' << max_val;


    return 0;
}