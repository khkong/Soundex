//
// Created by kyeonghwan on 18. 3. 6.
//

#ifndef SOUNDEX_SOUNDEXTABLE_H
#define SOUNDEX_SOUNDEXTABLE_H

#include <vector>
#include <map>

using namespace std;

class ISoundexTable {
public :
    virtual const vector<wchar_t>* getVowels() = 0;
    virtual const bool isExistVowel(const wchar_t wc) = 0;
    virtual const map<wchar_t, wchar_t>* getSoundexMap() = 0;
};

#endif //SOUNDEX_SOUNDEXTABLE_H
