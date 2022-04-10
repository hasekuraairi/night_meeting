/*
    フィボナッチ数列のn番目の各項を求めるプログラム
    普通に求める方法を取るので、nが大きくなるにつれて
    指数的に計算時間が増加
    計算時間： O( 1 + sqrt(5) / 2)^(n-1) )
*/

#include <iostream>
using namespace std;

long long int fibo1(int n) {
    // ベースケース
    if (n == 0 || n == 1) {
        return 1;
    }
    return fibo1(n - 1) + fibo1(n - 2);
}

int main() {
    int n;
    cin >> n;

    if (n > 0) {
        cout << "Fibonacci 1" << endl;
        auto startTime = clock();
        cout << fibo1(n - 1) << endl;
        auto endTime = clock();
        cout << "time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
    } else {
        cout << "Inputed nagative number or zero" << endl;
    }

    return 0;
}