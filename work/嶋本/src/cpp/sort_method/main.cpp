#include "sorter.cpp"
#include <ctime>
#include <random>

int main() {
    /*std::vector<int> data;
    data.push_back(3);
    data.push_back(5);
    data.push_back(2);
    data.push_back(1);
    data.push_back(4);*/

    // 0 ~ 100までのランダムな数字を100個用意
    std::vector<int> data(100000);
    std::srand(std::time(nullptr));
    const int MAX = 100;
    for (int i = 0; i < data.size(); ++i) {
        data[i] = rand() % MAX;
    }



    Sorter sorter(data);
    //sorter.showInputData();
    std::cout << std::endl;

    clock_t start = clock();
    
    //sorter.bubbleSort();
    //sorter.selectSort();
    //sorter.insertSort();
    sorter.margeSort(data, 0, data.size());

    clock_t end = clock();
    auto time = (double)(end - start) / CLOCKS_PER_SEC;

    //sorter.showSortedData();
    std::cout << "time: " << time << " sec" << std::endl;


    return 0;
}