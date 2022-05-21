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
    void swap(int &n, int &m);
public:
    Sorter(std::vector<int> &data);
    ~Sorter();

    // ソート群
    void bubbleSort();
    void selectSort();
    void insertSort();
    void margeSort(std::vector<int> &data, int left, int right);
    void quickSort(std::vector<int> &data, int left, int right);
    void shellSort();

    // 出力
    void showInputData();
    void showSortedData();
};

Sorter::Sorter(std::vector<int> &data) {
    this->data = data;
    this->sortedData = data;
}

Sorter::~Sorter() {
    this->data.clear();
    this->sortedData.clear();
}
