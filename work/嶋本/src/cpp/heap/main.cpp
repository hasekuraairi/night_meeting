#include <ctime>
#include <random>

#include "heap_controller.cpp"

int main() {
    std::vector<int> data(32);
    std::srand(std::time(nullptr));
    const int MAX = 1000;
    for (int i = 0; i < data.size(); ++i) {
        data[i] = rand() % MAX;
    }

    for (auto elem : data) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    HeapController heapCtrl(data);
    std::cout << "<---Created heap--->" << std::endl;
    heapCtrl.showHeap();

    heapCtrl.heapSort();
    std::cout << "<---Heap sorted--->" << std::endl;
    heapCtrl.showHeapSort();

    return 0;
}