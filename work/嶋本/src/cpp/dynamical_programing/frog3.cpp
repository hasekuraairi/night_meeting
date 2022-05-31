#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief 
 * 
 * @tparam T 
 * @param a 
 * @param b 
 */
template<class T> void chimin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    vector<long long> dp(N, INF);

    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        if (i + 1 < N) {
            chimin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < N) {
            chimin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }

    cout << dp[N - 1] << endl; 
}