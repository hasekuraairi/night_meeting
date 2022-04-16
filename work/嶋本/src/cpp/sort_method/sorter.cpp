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
        for (int j = i; j != 0; --j) {
            // 左側から段々とソートされる
            if (data[j - 1] > data[j]) {
                auto tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
    this->sortedData = data;
}

// インプットデータをコンソールに表示する
void Sorter::showInputData() {
    for (auto num : this->data) {
        std::cout << num << std::endl;
    }
}

// ソート後のデータをコンソールに表示する
void Sorter::showSortedData() {
    for (auto num : this->sortedData) {
        std::cout << num << std::endl;
    }
}