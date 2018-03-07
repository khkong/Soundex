#include <iostream>
#include "Soundex.h"

using namespace std;
int main() {
    //example
    Soundex* soundex = new Soundex();
    std::cout << "Россия -> ";
    string encode1 = soundex->encode("Россия", Global::LOCALE_TYPE::RU_RU);
    cout<<encode1<<endl;

    std::cout << "Russia -> ";
    string encode2 = soundex->encode(L"Russia", Global::LOCALE_TYPE::EN_US);
    cout<<encode2<<endl;
    delete soundex;
    return 0;
}