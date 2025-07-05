#include <bits/stdc++.h>

#define MAX_NM 50

using namespace std;

int n, m;
int ans_cnt = 0, ans_k = 1;
int min_k = INT_MAX, max_k = INT_MIN;
int grid[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

bool inRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void bfs(int r, int c, int k) {
    queue<pair<int,int>> q;
    visited[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        auto [cur_r, cur_c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nxt_r = cur_r + dr[d];
            int nxt_c = cur_c + dc[d];

            if (inRange(nxt_r, nxt_c) && !visited[nxt_r][nxt_c] && grid[nxt_r][nxt_c] > k) {
                visited[nxt_r][nxt_c] = true;
                q.push({nxt_r, nxt_c});
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> grid[r][c];
            min_k = min(min_k, grid[r][c]);
            max_k = max(max_k, grid[r][c]);
        }
    }

    for (int k = 1; k <= max_k; k++) {
        memset(visited, false, sizeof visited);
        int safe_area_cnt = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (!visited[r][c] && grid[r][c] > k) {
                    bfs(r, c, k);
                    safe_area_cnt++;
                }
            }
        }

        if (safe_area_cnt > ans_cnt) {
            ans_cnt = safe_area_cnt;
            ans_k = k;
        }
    }

    cout << ans_k << " " << ans_cnt << "\n";

    return 0;
}
