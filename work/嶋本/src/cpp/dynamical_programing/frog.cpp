#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;

    // 足場の高さ
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    // 動的計画法用の配列
    vector<long long> dp(N, INF);

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            // 初期条件
            dp[i] = 0;
        } else if (i == 1) {
            // 0番目から1番目は一段飛ばしでしか行けない
            dp[i] = abs(h[i] - h[i - 1]);
        } else {
            // 一段飛ばしor二段飛ばしでコストが低い方を選択
            dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                        dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }

    // N番目まで行くときの最小コストを表示
    cout << dp[N - 1] << endl;
}