/*
    単方向リストの実装
    insertの処理が未実装
    
    参考URL：https://qiita.com/yokoto/items/3bbe3754cf378d54f55c
*/

#include "UnidirectionalList.h"

UnidirectionalList::UnidirectionalList() { headNode = nullptr; }

UnidirectionalList::~UnidirectionalList() {
    Node *currentNode;
    Node *nextNode;
    currentNode = headNode;
    while (currentNode != nullptr) {
        // 次のノードのポインタをセット
        nextNode = currentNode->nextNode;
        // 現在のノードを削除
        delete currentNode;
        // 次のノードを現在のノードにセット
        currentNode = nextNode;
    }
}

Node *UnidirectionalList::createNode(int data) {
    Node *newNode;
    // ノードの追加
    newNode = new Node;
    newNode->data = data;
    newNode->nextNode = nullptr;
    return newNode;
}

void UnidirectionalList::add(int data) {
    Node *newNode = createNode(data);
    if (headNode == nullptr) {
        headNode = newNode;
    } else {
        // 移動用ポインタ
        Node *nodePtr = headNode;
        // ポインタを辿る処理
        while (nodePtr->nextNode != nullptr) {
            nodePtr = nodePtr->nextNode;
        }
        // ポインタの繋ぎ変え
        nodePtr->nextNode = newNode;
    }
}

void UnidirectionalList::del() {
    Node *currentNode = headNode;
    Node *prevNode;
    if (headNode == nullptr) {
        return;
    }
    // 最後尾のポインタまで辿る処理
    while (currentNode->nextNode != nullptr) {
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }
    prevNode->nextNode = nullptr;
    delete currentNode;
}

// リストの要素を全て表示
void UnidirectionalList::show() {
    Node *currentNode = headNode;
    // 追加されていないときはなにもしない
    if (headNode == nullptr) {
        return;
    }
    while (currentNode != nullptr) {
        cout << currentNode->data << endl;
        currentNode = currentNode->nextNode;
    }
}