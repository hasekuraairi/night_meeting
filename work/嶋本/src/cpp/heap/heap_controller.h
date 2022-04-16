#include <algorithm>
#include <iostream>
#include <vector>

class HeapController {
   private:
    std::vector<int> data;
    std::vector<int> sortedData;
    void createHeap();
    void upHeap(int i);
    void downHeap(int i);
    void swap(int &n, int &m);

   public:
    HeapController(std::vector<int> &data);
    ~HeapController();
    void heapSort();
    void showHeap();
    void showHeapSort();
};

HeapController::HeapController(std::vector<int> &data) {
    this->data = data;
    this->sortedData = data;
    createHeap();
}

HeapController::~HeapController() { data.clear(); }
