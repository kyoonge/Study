#include "Print.h"
#include <sstream>

int main() {
    {
        std::istringstream input("52 102 1 abc 2382");
        std::ostringstream output;
        PrintIntegers(input, output);
        std::cout << output.str() << std::endl;
    }
    {
        std::istringstream input("2.23 -1912.87233125 2323 def 1");
        std::ostringstream output;
        PrintMaxFloat(input, output);
        std::cout << output.str() << std::endl;
    }

    return 0;
}