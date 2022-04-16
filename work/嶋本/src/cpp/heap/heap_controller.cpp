/*
    ヒープを実装
    ヒープは不等式　親ノード > 子ノード（あるいは、 親ノード <
   子ノード）を満たす木構造

    ヒープを2分木としたとき、配列でヒープを実装すると配列のインデックスとノード番号を対応付けることができる
    たとえば配列aにおいて、a[0]はルートとすると、a[1]はa[0]の左側の子ノード,
   a[2]は右側の子ノードを表す
    同様に、a[3]はa[1]の左側の子ノード、a[4]はa[1]の右側の子ノードを表す
    さらに、a[5]はa[2]の左側の子ノード、a[6]はa[2]の右側の子ノードを表す

    参考URL: https://novnote.com/priority-queue-heapsort-impl-cpp/565/
*/

#include "heap_controller.h"

// ヒープを構築する関数
void HeapController::createHeap() {
    for (int i = 1; i < data.size(); ++i) {
        upHeap(i);
    }
}

// ヒープの順序を満たすようにノードを移動させる関数
// 上に移動させていくイメージ
void HeapController::upHeap(int childIndex) {
    // n = 0 はルートノードのインデックス
    // 親ノードが子ノードよりも小さとき入れ替える
    // ルートまで来たら入れ替え処理は終了
    while (childIndex > 0) {
        // 親ノードのインデックス
        int parentIndex = (childIndex - 1) / 2;
        // 子ノード > 親ノードのときは入れ替え
        if (data[childIndex] > data[parentIndex]) {
            swap(data[childIndex], data[parentIndex]);
        }
        childIndex = parentIndex;
    }
}

// ヒープの順序を満たすようにノードを移動させる関数
// 下に移動させていくイメージ
void HeapController::downHeap(int index) {
    // ヒープの最後尾の値をルートに持ってくる
    data[0] = data[index];
    int parentIndex = 0;
    // whileの条件式について
    // childIndex = 2 * parentIndex + 1 or 2 * parentIndex + 2 より
    // max(parentIndex) = Int(max(childIndex) + 1 ) / 2　が成り立つ
    // childIndexの最大値は配列のインデックスの最大値 N - 1
    // よって、parentIndex <  N /2 が成り立つ
    // もっと簡単に言うと、(配列サイズ / 2) 以降のインデックスを持つ要素は
    // 木構造の葉にあたる。葉の定義から葉が親になることはないので、whileの条件式となる
    while (parentIndex < index / 2) {
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        // 左右の子ノードを比較して大きい方のノードのインデックスを保持
        int childIndex = data[leftChildIndex] > data[rightChildIndex]
                             ? leftChildIndex
                             : rightChildIndex;
        // 子ノード > 親ノードのときは入れ替え
        if (data[childIndex] > data[parentIndex]) {
            swap(data[childIndex], data[parentIndex]);
        }
        parentIndex = childIndex;
    }
}

// 生成されたヒープを用いてソートする
void HeapController::heapSort() {
    for (int i = data.size() - 1; i >= 0; --i) {
        sortedData[i] = data[0];
        downHeap(i);
    }
}

// ノードの交換用の関数
void HeapController::swap(int &n, int &m) {
    int tmp = n;
    n = m;
    m = tmp;
}

// コンソールにヒープを表示するための関数
void HeapController::showHeap() {
    for (auto elem : data) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

// コンソールにヒープソートの結果を表示するための関数
void HeapController::showHeapSort() {
    for (auto elem : sortedData) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}