#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bans = 0;
int wans = 0;
void dc(vector<vector<int>>& v, int i, int j, int size) {
    int check = false;
    int wcount = 0;
    int bcount = 0;
    for (int a = i; a <i+ size; a++) {
        for (int b = j; b <j+ size; b++) {
            if (v[a][b] == 0) {
                wcount++;
            }
            else {
                bcount++;
            }
        }
    }


    if (wcount == size * size) {
        wans++;
        //cout << i << " " << j << " " << size << "\n";
        return;
    }
    
    if (bcount == size*size) {
        bans++;
        //cout << i << " " << j << " " << size << "\n";
        return;
    }
    

    if (size == 1){
        return;
    }
    dc(v, i + size/2, j, size / 2);
    dc(v, i, j + size/2, size / 2);
    dc(v, i + size/2, j + size/2, size / 2);
    dc(v, i, j, size / 2);
}

int main() {
    int n, m;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    dc(v,0, 0, n);
    
    cout << wans << "\n" << bans << "\n";

    return 0;
}
