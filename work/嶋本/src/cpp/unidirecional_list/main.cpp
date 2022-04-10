#include "UnidirectionalList.cpp"

int main() {
    UnidirectionalList uDlist;
    cout << "リストの最後尾に要素を追加" << endl;
    uDlist.add(2);
    uDlist.add(4);
    uDlist.add(6);
    uDlist.show();

    cout << endl;

    cout << "リストの最後尾の要素を削除" << endl;
    uDlist.del();
    uDlist.show();

    return 0;
}