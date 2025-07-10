#include <bits/stdc++.h>

#define MAX_N 100
#define DIR_N 4

using namespace std;

int n, ans_k, ans_cnt;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int cur_cnt;
int dr[DIR_N] = {-1, 0, 1, 0};
int dc[DIR_N] = {0, -1, 0, 1};

bool inRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

bool canGo(int r, int c) {
    if (!inRange(r, c)) {
        return false;
    }

    if (visited[r][c]) {
        return false;
    }

    return true;
}

void dfs(int r, int c) {
    visited[r][c] = true;
    cur_cnt++;
    
    for (int d = 0; d < DIR_N; d++) {
        int nxt_r = r + dr[d];
        int nxt_c = c + dc[d];

        if (canGo(nxt_r, nxt_c) && arr[r][c] == arr[nxt_r][nxt_c]) {
            dfs(nxt_r, nxt_c);
        }
    }
}

int main(void) {
    cin >> n;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> arr[r][c];
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (visited[r][c]) {
                continue;
            }
            
            // 순회 전 초기화
            cur_cnt = 0;

            // dfs 시작
            dfs(r, c);

            // 결과 저장
            if (cur_cnt >= 4) { // 터진 블럭 갯수 저장
                ans_k++;
            }
            ans_cnt = max(ans_cnt, cur_cnt); // 가장 큰 블럭 갯수 저장
        }
    }

    cout << ans_k << " " << ans_cnt << "\n";

    return 0;
}
