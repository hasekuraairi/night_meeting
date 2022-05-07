#include "searcher.cpp"

int main() {
    std::string str;
    std::cin >> str;
    Searcher searcher = Searcher(str);

    std::string searchStr;
    std::cin >> searchStr;

    std::cout << searcher.naiveMethod(searchStr) << std::endl;
    //std::cout << searcher.kmpMethod(searchStr) << std::endl;

    return 0;
}