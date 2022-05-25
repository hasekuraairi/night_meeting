/*
    編集距離を動的計画法で解く

    編集距離：文字列Sを文字列Tに変換するときの以下処理の
             最小組み合わせ数のこと

    ・変更：S中の文字を１つ任意の文字に変更
    ・削除：S中の文字を１つ選んで削除
    ・挿入：S中の好きな箇所に任意の文字を１つ挿入
          （編集距離算出においてTから文字を削除する処理と等価）
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const int INF = 1 << 29;

int calcEditDistance(string &S, string &T, vector<vector<int>> &dp) {
// DPテーブル
    for (int i = 0; i <= S.size(); ++i) {
        for (int j = 0; j <= T.size(); ++j) {
            // 変換操作
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }

            // 削除操作
            if (i > 0) {
                chmin(dp[i][j], dp[i - 1][j] + 1);
            }

            // 挿入操作
            if (j > 0) {
                chmin(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }

    return dp[S.size()][T.size()];
}


int main() {
    string S = "logistic";
    string T = "algorithm";

    // DPテーブル
    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));

    // DP初期条件
    dp[0][0] = 0;

    int res = calcEditDistance(S, T, dp);

    cout << res << endl;

    return 0;
}
