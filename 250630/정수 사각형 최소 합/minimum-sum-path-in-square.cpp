#include <bits/stdc++.h>

#define MAX_N 100
#define DIR_N 4

using namespace std;

int n;
int grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<pair<int,int>> q;

bool inRange(int r, int c) {
    return r >= 0 && r < n && c >=0 && c < n;
}

bool canGo(int r, int c) {
    return inRange(r, c) && (!visited[r][c]);
}

void bfs() {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};

    while (!q.empty()) {
        auto [cur_r, cur_c] = q.front();
        q.pop();
        visited[cur_r][cur_c] = true;

        for (int d = 0; d < DIR_N; d++) {
            int nxt_r = cur_r + dr[d];
            int nxt_c = cur_c + dc[d];
            
            if (canGo(nxt_r, nxt_c)) {
                int cur_w = dp[cur_r][cur_c];
                int nxt_w = grid[nxt_r][nxt_c];

                dp[nxt_r][nxt_c] = min(dp[nxt_r][nxt_c], cur_w + nxt_w);
                q.push({nxt_r, nxt_c});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> grid[r][c];
            dp[r][c] = INT_MAX;
        }
    }
    
    dp[0][n - 1] = grid[0][n - 1];
    q.push({0, n - 1});
    bfs();

    // for (int r = 0; r < n; r++) {
    //     for (int c = 0; c < n; c++) {
    //         cout << dp[r][c] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[n - 1][0] << "\n";

    return 0;
}