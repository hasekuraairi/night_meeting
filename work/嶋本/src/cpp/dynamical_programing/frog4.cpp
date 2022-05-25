#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60;

// 普通の再起処理（時間かかる）
long long rec(int i, vector<long long> &h) {
    if (i == 0) {
        return 0;
    }

    long long res = INF;

    chmin(res, rec(i - 1, h) + abs(h[i] - h[i - 1]));

    if (i > 1) {
        chmin(res, rec(i - 2, h) + abs(h[i] - h[i - 2]));
    }

    return res;
}

// メモ化再起
long long memoRec(int i, vector<long long> &h, vector<long long> &dp) {
    if (dp[i] < INF) {
        return dp[i];
    }

    if (i == 0) {
        return 0;
    }

    long long res = INF;

    chmin(res, memoRec(i - 1, h, dp) + abs(h[i] - h[i - 1]));

    if (i > 1) {
        chmin(res, memoRec(i - 2, h, dp) + abs(h[i] - h[i - 2]));
    }

    return dp[i] = res;
}

int main() {
    vector<long long> h = {2, 9, 4, 5, 1, 6, 10};
    int N = h.size();
    vector<long long> dp(N, INF);

    //cout << rec(N - 1, h) << endl;

    cout << memoRec(N - 1, h, dp) << endl;

    return 0;
}
