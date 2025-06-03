#include <bits/stdc++.h>

#define MAX_N 20

using namespace std;

int n, ans;
bool grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int,int>> bomb_spot;
vector<int> selected;

vector<pair<int,int>> shape1 = {{-2,0}, {-1,0}, {0,0}, {1,0}, {2,0}};
vector<pair<int,int>> shape2 = {{-1,0}, {0,1}, {1,0}, {0,-1}, {0,0}};
vector<pair<int,int>> shape3 = {{-1,-1}, {-1,1}, {1,1}, {1,-1}, {0,0}};

vector<vector<pair<int,int>>> shapes = {{}, shape1, shape2, shape3};

bool inRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void calc() {
    int explosion_cnt = 0;
    bool exploded[MAX_N][MAX_N];
    memset(exploded, false, sizeof exploded);

    for (int i = 0; i < selected.size(); i++) {
        int shape_idx = selected[i];
        auto [cur_r, cur_c] = bomb_spot[i];

        for (auto nxt : shapes[shape_idx]) {
            auto [nxt_r, nxt_c] = nxt;
            nxt_r += cur_r;
            nxt_c += cur_c;

            if (inRange(nxt_r, nxt_c) && !exploded[nxt_r][nxt_c]) {
                explosion_cnt++;
                exploded[nxt_r][nxt_c] = true;
            }
        }
    }

    // for (auto k : selected) cout << k << " "; cout <<"\n";
    // for (int i = 0 ; i < n; i++) {
    //     for (int j = 0; j < n; j ++) {
    //         cout << exploded[i][j] << " ";
    //     }cout << "\n";
    // }cout << "\n";

    ans = max(ans, explosion_cnt);
}

void comb(int idx) {
    if (selected.size() == bomb_spot.size()) {
        calc();
        return;
    }
    if (idx >= bomb_spot.size()) {
        return;
    }

    for (int i = 1; i <= 3; i++) {
        selected.push_back(i);

        comb(idx + 1);

        selected.pop_back();
    }
}

int main() {
    cin >> n;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int bomb;
            cin >> bomb;
            grid[r][c] = bomb;

            if (bomb == 1) {
                bomb_spot.push_back({r, c});
            }
        }
    }

    comb(0);

    cout << ans << "\n";
}
