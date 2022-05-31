#include <iostream>
#include <vector>
using namespace std;

template <class T>
void chMin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60;

int main() {
    int N = 2;
    vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            cin >> c[i][j];
        }
    }

    vector<long long> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            chMin(dp[i], dp[j] + c[j][i]);
        }
    }

    cout << dp[N] << endl;
}