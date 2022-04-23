#include "sorter.h"

// バブルソート
void Sorter::bubbleSort() {
    std::vector<int> data;
    // 元データが書き換わらないようにコピーを用意する
    std::copy(this->data.begin(), this->data.end(), std::back_inserter(data));

    for (int i = 0; i < data.size() - 1; ++i) {
        for (int j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                // 隣同士の要素を 不等式, 左要素 <= 右要素 が
                // 成り立つように交換
                auto tmp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = tmp;
            }
        }
    }
    this->sortedData = data;
}

// 選択ソート
void Sorter::selectSort() {
    std::vector<int> data;
    // 元データが書き換わらないようにコピーを用意する
    std::copy(this->data.begin(), this->data.end(), std::back_inserter(data));

    for (int i = 0; i < data.size() - 1; ++i) {
        std::pair<int, int> elemOnIndex(-1, 9999);
        // 最小値を線形探索
        for (int j = i; j < data.size(); ++j) {
            if (data[j] < elemOnIndex.second) {
                // インデックスと最小値を保持
                elemOnIndex.first = j;
                elemOnIndex.second = data[j];
            }
        }

        // 探索した最小値と
        // ソート確定前の一番小さいインデックスの要素を
        // 交換
        auto tmp = data[i];
        data[i] = elemOnIndex.second;
        data[elemOnIndex.first] = tmp;
    }
    this->sortedData = data;
}

void Sorter::insertSort() {
    std::vector<int> data;
    // 元データが書き換わらないようにコピーを用意する
    std::copy(this->data.begin(), this->data.end(), std::back_inserter(data));

    for (int i = 1; i < data.size(); ++i) {
        // 挿入する要素
        std::pair<int, int> insertElem(i, data[i]);
        for (int j = i; j > 0; --j) {
            // 左側から段々とソートされる
            if (data[j - 1] > insertElem.second) {
                // 後ろにずらす
                data[j] = data[j - 1];
                insertElem.first--;
            } else {
                break;
            }
        }
        // 要素を目的の場所に挿入
        data[insertElem.first] = insertElem.second;
    }
    this->sortedData = data;
}

// マージソート
// 再帰処理でデータを分割していく
// 分割し終えればソートして、マージしていく
void Sorter::margeSort(std::vector<int> &data, int left, int right) {
    // ベースケース
    if (right - left == 1) {
        return;
    }

    int mid = (right + left) / 2;
    // 左半分をソート
    margeSort(data, left, mid);
    // 右半分をソート
    margeSort(data, mid, right);

    // 左ソートの結果と右ソートの結果をコピー
    // 右ソートの結果は左右反転にしておくと、
    // 先端と最端の比較することでソートができるようになる
    std::vector<int> buf;
    for (int i = left; i < mid; ++i) {
        buf.push_back(data[i]);
    }
    for (int i = right - 1; i >= mid; --i) {
        buf.push_back(data[i]);
    }

    // マージ処理
    int indexLeft = 0;
    int indexRight = buf.size() - 1;
    for (int i = left; i < right; ++i) {
        if (buf[indexLeft] <= buf[indexRight]) {
            // 先端を採用
            // インデックスは要素が代入されてから+1される
            data[i] = buf[indexLeft++];
        } else {
            // 最端を採用
            // インデックスは要素が代入されてから-1される
            data[i] = buf[indexRight--];
        }
    }

    this->sortedData = data;
}

// インプットデータをコンソールに表示する
void Sorter::showInputData() {
    std::cout << "<--- Inputted Data --->" << std::endl;
    for (auto num : this->data) {
        std::cout << num << "  ";
    }
}

// ソート後のデータをコンソールに表示する
void Sorter::showSortedData() {
    std::cout << "<--- Sorted Data --->" << std::endl;
    for (auto num : this->sortedData) {
        std::cout << num << "  ";
    }
}