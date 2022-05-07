#include "searcher.h"

int Searcher::naiveMethod(std::string searchStr) {
    int count = 0;
    int fix = 0;
    int result = -1;
    while (count < searchStr.length() && fix < str.length()) {
        if (str[count + fix] == searchStr[count]) {
            if (result == -1) {
                result = count + fix; // 文字列の中に探索文字列が含まれている位置を保持
            }
            ++count;
        } else {
            // 位置が不一致なら一文字ずらして再探索
            ++fix;
            count = 0;
            result = -1;
        }
    }

    return result;
}

// KMP法
int Searcher::kmpMethod(std::string searchStr) {
    std::vector<int> table = Searcher::genKmpTable(searchStr);
    int tableSize = table.size();
    int count = 0;
    int fix = 0;
    int result = -1;

    while (count < tableSize && fix <= tableSize) {
        if (this->str[count + fix] == searchStr[count]) {
            if (result == -1) {
                result = count + fix;
            }
            ++count;
        } else {
            count = 0;
            fix = count + fix - table[count];
            result = -1;
        }
    }

    return result;
}

// KMP法用のテーブル生成
std::vector<int> Searcher::genKmpTable(std::string searchStr) {
    int size = searchStr.length();
    std::vector<int> table(size, 0);
    table[0] = -1;

    for (int i = 2; i < size; ++i) {
        if (searchStr[i] == searchStr[0]) {
            int j = i + 1;
            int k = 1;
            while (j < size) {
                if (searchStr[j] != searchStr[0]) {
                    table[j++] = k++;
                } else {
                    i = j - 1;
                    break;
                }
            }
        }
    }

    return table;
}
