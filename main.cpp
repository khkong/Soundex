#include <iostream>
#include "Soundex.h"

using namespace std;
int main() {
    //example
    std::cout << "Россия -> ";
    string encode1 = Soundex::getInstance()->encode("Россия", Global::LOCALE_TYPE::RU_RU);
    cout<<encode1<<endl;

    std::cout << "Russia -> ";
    string encode2 = Soundex::getInstance()->encode(L"Russia", Global::LOCALE_TYPE::EN_US);
    cout<<encode2<<endl;
    return 0;
}