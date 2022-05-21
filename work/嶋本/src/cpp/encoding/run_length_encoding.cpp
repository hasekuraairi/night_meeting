#include <iostream>

std::string runLengthEncoding(std::string &str) {
    std::string res = "";
    for (int i = 0; i < str.length(); ++i) {
        int j = i;
        while(true) {
            if (str[j] != str[j + 1]) {
                int num = j - i + 1;
                res += str[j] + std::to_string(num);
                i = j;
                break;
            } 
            ++j;
        }
    }
    return res;
}

int main() {
    std::string str = "aaaaabbbbbbccccccccoffeesplaaaaaashuuum";
    std::cout << "original string: " + str + ", length = " << str.length() << std::endl;
    std::string encoded = runLengthEncoding(str);
    std::cout << "encoded string: " + encoded << ", length = " << encoded.length() << std::endl;
    return 0;
}