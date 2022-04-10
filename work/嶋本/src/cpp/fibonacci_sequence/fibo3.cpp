/*
    フィボナッチ数列のn番目の各項を求めるプログラム
    行列累乗版
    計算時間： O(log N) らしい？
    https://qiita.com/flour/items/9f8a20112f45f0ee5f71
*/

#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

int main() {
    MatrixXd fiboM(2, 2);
    MatrixXd fiboV(2, 1);

    // ベクトル定義
    // 第２成分が求めたい答えとなる
    fiboV(0) = 1;
    fiboV(1) = 0;

    // 行列定義
    fiboM(0, 0) = 1;
    fiboM(1, 0) = 1;
    fiboM(0, 1) = 1;
    fiboM(1, 1) = 0;

    // 行列累乗計算用の一時変数 
    MatrixXd tmpM = fiboM;

    int n;
    cin >> n;

    if (n > 0) {
        cout << "Fibonacci 3" << endl;
        auto startTime = clock();
        // 行列累乗計算
        for (int i = 1; i < n; ++i) {
            tmpM *= fiboM;
        }
        fiboV = tmpM * fiboV;
        auto endTime = clock();
        cout << fiboV(1) << endl;
        cout << "time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
    } else {
        cout << "Inputed nagative number or zero" << endl;
    }

    return 0;
}