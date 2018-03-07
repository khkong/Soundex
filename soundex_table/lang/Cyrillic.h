//
// Created by kyeonghwan on 18. 3. 7.
//

#ifndef SOUNDEX_CYRILLIC_H
#define SOUNDEX_CYRILLIC_H

#include <algorithm>
#include "../ISoundexTable.h"

class Cyrillic : public ISoundexTable{
private:
    static ISoundexTable* mInstance;
    vector<wchar_t> mVecVowels;
    map<wchar_t, wchar_t> mMapSoundex;

public :
    Cyrillic();
    ~Cyrillic();

    static ISoundexTable* getInstance(){
        if(mInstance==nullptr)
            mInstance = new Cyrillic();
        return mInstance;
    }
    const bool isExistVowel(const wchar_t wc) override;
    const vector<wchar_t>* getVowels() override;
    const map<wchar_t, wchar_t>* getSoundexMap() override;
};


#endif //SOUNDEX_CYRILLIC_H
