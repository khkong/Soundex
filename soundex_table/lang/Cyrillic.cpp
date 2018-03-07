//
// Created by kyeonghwan on 18. 3. 7.
//
#include "Cyrillic.h"

ISoundexTable* Cyrillic::mInstance = new Cyrillic();

Cyrillic::Cyrillic(){
    //"vowels": ['у', 'е', 'ы', 'а', 'о', 'э', 'я', 'и', 'ю', 'ь', 'ъ', 'й'],
    mVecVowels.push_back(L'У');
    mVecVowels.push_back(L'Е');
    mVecVowels.push_back(L'Ы');
    mVecVowels.push_back(L'А');
    mVecVowels.push_back(L'О');
    mVecVowels.push_back(L'Э');
    mVecVowels.push_back(L'Я');
    mVecVowels.push_back(L'И');
    mVecVowels.push_back(L'Ю');
    mVecVowels.push_back(L'Ь');
    mVecVowels.push_back(L'Ъ');
    mVecVowels.push_back(L'Й');
    sort(mVecVowels.begin(), mVecVowels.end());

    mMapSoundex[L'Б'] = L'1';
    mMapSoundex[L'П'] = L'1';
    mMapSoundex[L'Ф'] = L'1';
    mMapSoundex[L'В'] = L'1';

    mMapSoundex[L'С'] = L'2';
    mMapSoundex[L'Ц'] = L'2';
    mMapSoundex[L'З'] = L'2';
    mMapSoundex[L'К'] = L'2';
    mMapSoundex[L'Г'] = L'2';
    mMapSoundex[L'Х'] = L'2';

    mMapSoundex[L'Т'] = L'3';
    mMapSoundex[L'Д'] = L'3';

    mMapSoundex[L'Л'] = L'4';
    mMapSoundex[L'Й'] = L'4';

    mMapSoundex[L'М'] = L'5';
    mMapSoundex[L'Н'] = L'5';

    mMapSoundex[L'Р'] = L'6';
}

Cyrillic::~Cyrillic(){

}

const bool Cyrillic::isExistVowel(const wchar_t wc) {
    return binary_search(mVecVowels.begin(), mVecVowels.end(), wc);
}


const vector<wchar_t> *Cyrillic::getVowels() {
    return &mVecVowels;
}

const map<wchar_t, wchar_t> *Cyrillic::getSoundexMap() {
    return &mMapSoundex;
};