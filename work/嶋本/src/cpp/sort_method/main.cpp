#include "sorter.cpp"

int main() {
    std::vector<int> data;
    data.push_back(3);
    data.push_back(5);
    data.push_back(2);
    data.push_back(1);
    data.push_back(4);


    Sorter sorter(data);
    sorter.showInputData();
    std::cout << std::endl;
    
    //sorter.bubbleSort();
    //sorter.selectSort();
    sorter.insertSort();

    sorter.showSortedData();

    return 0;
}