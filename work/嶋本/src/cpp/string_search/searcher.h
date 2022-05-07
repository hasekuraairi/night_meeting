#include <string>
#include <vector>
#include <iostream>

class Searcher {
private:
    std::string str;
public:
    Searcher(std::string str);
    ~Searcher();
    int naiveMethod(std::string searchStr);
    int kmpMethod(std::string searchStr);
    int bmMethod(std::string searchStr);
    std::vector<int> genKmpTable(std::string searchStr);
    std::string getStr() {return str;}
};

Searcher::Searcher(std::string str) {
    this->str = str;
}

Searcher::~Searcher() {
}
