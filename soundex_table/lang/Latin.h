//
// Created by kyeonghwan on 18. 3. 7.
//

#ifndef SOUNDEX_LATIN_HPP
#define SOUNDEX_LATIN_HPP

#include <algorithm>
#include "../ISoundexTable.h"

using namespace std;

class Latin : public ISoundexTable{
private :
    static ISoundexTable* mInstance;
    vector<wchar_t> mVecVowels;
    map<wchar_t, wchar_t> mMapSoundex;

public :
    Latin();
    ~Latin();

    static ISoundexTable* getInstance(){
        if(mInstance==nullptr)
            mInstance = new Latin();
        return mInstance;
    }
    const bool isExistVowel(const wchar_t wc) override;
    const vector<wchar_t>* getVowels() override;
    const map<wchar_t, wchar_t>* getSoundexMap() override;

};


#endif //SOUNDEX_LATIN_HPP
