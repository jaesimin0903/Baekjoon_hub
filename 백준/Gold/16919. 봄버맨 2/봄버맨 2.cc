#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BOMB {
    int x, y, timer;
    BOMB(int r, int c, int t) :x(c), y(r), timer(t) {}
};

queue<BOMB> q;
char a[200][200];
int r, c, n;
char ans[5][200][200];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void run() {
    int sz = q.size();
    for (int i = 0; i < sz; ++i) {
        --q.front().timer;
        q.push(q.front());
        q.pop();
    }
}

void setup() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == '.') {
                a[i][j] = 'O';
                q.push({ i,j,3 });
            }
        }
    }
}

bool safe(int x, int y) {
    return (x >= 0 && x < c && y >= 0 && y < r);
}

void boom() {
    int sz = q.size();
    for (int i = 0; i < sz; ++i) {
        auto now = q.front();
        q.pop();
        int x = now.x;
        int y = now.y;
        now.timer -= 1;

        if (now.timer == 0) {
            a[y][x] = '.';
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (safe(nx, ny)) {
                    a[ny][nx] = '.';
                }
            }
            continue;
        }
        if (a[y][x] == '.') {
            continue;
        }
        q.push(now);
    }
}

void save(int idx) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ans[idx][i][j] = a[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> n;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'O') {
                q.push({ i, j, 3 });
            }
        }
    }

    if (n == 1) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << a[i][j];
            }
            cout << '\n';
        }
        return 0;
    }

    for (int t = 1; t <= 5; ++t) {
        if (t == 1) {
            run();
            continue;
        }
        switch (t % 2) {
        case 0:
            run();
            setup();
            break;
        case 1:
            boom();
            break;
        }
        save((t - 1) % 4);
    }

    int idx = (n - 1) % 4;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << ans[idx][i][j];
        }
        cout << '\n';
    }

    return 0;
}
