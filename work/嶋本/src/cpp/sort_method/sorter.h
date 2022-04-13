/*
    色々なソートを実装してみる予定
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Sorter {
private:
    std::vector<int> data;
    std::vector<int> sortedData;
public:
    Sorter(std::vector<int> &data);
    ~Sorter();

    // ソート群
    void bubbleSort();
    void selectSort();

    // 出力
    void showInputData();
    void showSortedData();
};

Sorter::Sorter(std::vector<int> &data) {
    this->data = data;
}

Sorter::~Sorter() {
    this->data.clear();
}
