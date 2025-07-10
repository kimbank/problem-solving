#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 1;
int arr[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, negative_cnt = 0;
    long long sum = 0, max_sum = LLONG_MIN;

    for(int right = 0; right < n; right++) {
        // 오른쪽 포인터의 원소 추가
        sum += arr[right];
        if(arr[right] < 0) negative_cnt++;

        // 음수가 k개를 초과하면, 왼쪽 포인터 이동
        while(negative_cnt > k && left <= right) {
            if(arr[left] < 0) negative_cnt--;
            sum -= arr[left];
            left++;
        }

        // 조건 만족 시 최대 합 갱신
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << "\n";
    return 0;
}
