#include <iostream>
using namespace std;

// リストのノード
struct Node {
    int data;
    // 次のノードのポインタ
    struct Node *nextNode;
};

class UnidirectionalList {
private:
    // リストの先頭ノードのポインタ
    Node *headNode;

public:
    // コンストラクタ
    UnidirectionalList(); 

    // デストラクタ
    ~UnidirectionalList();

    // ノード生成
    Node *createNode(int data);

    // リストの一番後ろにデータを追加
    void add(int data); 

    // リストの一番後ろのデータを消去
    void del(); 
    
    // リストの要素を全て表示
    void show();
};