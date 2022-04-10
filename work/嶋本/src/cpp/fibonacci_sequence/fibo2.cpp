/*
    フィボナッチ数列のn番目の各項を求めるプログラム
    計算量短縮のため計算結果を記憶しておく方法（キャッシュ化、メモ化）を取る
    計算時間： O(N)
*/

#include <iostream>
#include <vector>
using namespace std;

long long int fibo2(int n, vector<long long int> &memo) {
    // ベースケース
    if (n == 0 || n == 1) {
        return 1;
    }

    // 計算値をメモ
    if (memo[n] == -1) {
        memo[n] = fibo2(n - 1, memo) + fibo2(n - 2, memo);
    }

    return memo[n];
}

int main() {
    int n;
    cin >> n;

    // フィボナッチ数列の各項の計算結果を保持する配列
    // 初期値はフィボナッチ数列が取り得ない-1にしておく
    vector<long long int> memo(n, -1);

    if (n > 0) {
        cout << "Fibonacci 2" << endl;
        auto startTime = clock();
        cout << fibo2(n - 1, memo) << endl;
        auto endTime = clock();
        cout << "time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC
             << endl;
    } else {
        cout << "Inputed nagative number or zero" << endl;
    }

    return 0;
}