#include <iostream>
#include <vector>
using namespace std;

// 比較して最大の値に更新
template <class T>
void chMax(T &a, T b) {
    if (a < b) {
        a = b;
    }
}

struct Goods {
    long long weight;
    long long value;
};

long long solveKnapsackProblem(vector<Goods> &goodsList, long long W,
                               vector<vector<long long>> &dp,
                               vector<vector<long long>> &prevW) {
    int N = goodsList.size();
    for (int i = 0; i < N; ++i) {       // 品物についてのループ
        for (int w = 0; w <= W; ++w) {  // 重量についてのループ

            // i番目の品物を選ぶとき
            if (w >= goodsList[i].weight) {
                // 個数制限があるとき
                long long update =
                    dp[i][w - goodsList[i].weight] + goodsList[i].value;

                // 個数制限がないとき
                // long long update = dp[i + 1][w - goodsList[i].weight] +
                // goodsList[i].value;

                if (dp[i + 1][w] < update) {
                    dp[i + 1][w] = update;
                    prevW[i + 1][w] = w - goodsList[i].weight;
                }
            }

            // i番目の品物を選ばないとき
            if (dp[i + 1][w] < dp[i][w]) {
                dp[i + 1][w] = dp[i][w];
                prevW[i + 1][w] = w;
            }
        }
    }

    return dp[N][W];
}

void showCombination(int W, vector<vector<long long>> &prevW,
                vector<Goods> &goodsList) {
    int curWeight = W;
    for (int i = goodsList.size() - 1; i >= 0; --i) {
        // i番目の品物を選んでいた場合
        if (prevW[i + 1][curWeight] == curWeight - goodsList[i].weight) {
            cout << i + 1 << "番目, "
                 << "Weight: " << goodsList[i].weight
                 << ", value: " << goodsList[i].value << endl;
        }

        curWeight = prevW[i + 1][curWeight];
    }
}

int main() {
    long long W;
    cout << "Max Weight: ";
    cin >> W;

    vector<Goods> goodsList = {{1, 3}, {1, 3}, {3, 5}, {3, 5}, {3, 5},
                               {3, 5}, {4, 8}};

    int N = goodsList.size();

    // DPテーブル 価値の累積結果を保持
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    // 組み合わせ復元用テーブル
    vector<vector<long long>> prevW(N + 1, vector<long long>(W + 1, 0));

    long long res = solveKnapsackProblem(goodsList, W, dp, prevW);

    // 結果出力処理
    cout << "Max Value: " << res << endl;

    // 組み合わせ出力処理
    showCombination(W, prevW, goodsList);

    return 0;
}