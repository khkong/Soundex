//
// Created by kyeonghwan on 18. 3. 7.
//
#include "Latin.h"

ISoundexTable* Latin::mInstance = new Latin();

Latin::Latin() {
    //L'A', L'E', L'I', L'O', L'U', L'Y'
    mVecVowels.push_back(L'A');
    mVecVowels.push_back(L'À');
    mVecVowels.push_back(L'Á');
    mVecVowels.push_back(L'Â');
    mVecVowels.push_back(L'Ã');
    mVecVowels.push_back(L'Ä');
    mVecVowels.push_back(L'Å');
    mVecVowels.push_back(L'Æ');
    mVecVowels.push_back(L'Ą');
    mVecVowels.push_back(L'Ă');
    //À Á Â Ã Ä Å Æ Ą Ă
    mVecVowels.push_back(L'E');
    mVecVowels.push_back(L'È');
    mVecVowels.push_back(L'É');
    mVecVowels.push_back(L'Ê');
    mVecVowels.push_back(L'Ë');
    mVecVowels.push_back(L'Ē');
    mVecVowels.push_back(L'Ė');
    mVecVowels.push_back(L'Ę');
    mVecVowels.push_back(L'Ě');
    mVecVowels.push_back(L'Ĕ');
    //È É Ê Ë Ē Ė Ę Ě Ĕ
    mVecVowels.push_back(L'I');
    mVecVowels.push_back(L'Ì');
    mVecVowels.push_back(L'Í');
    mVecVowels.push_back(L'Î');
    mVecVowels.push_back(L'Ï');
    mVecVowels.push_back(L'Ī');
    mVecVowels.push_back(L'Į');
    mVecVowels.push_back(L'I');
    //Ì Í Î Ï Ī Į I
    mVecVowels.push_back(L'O');
    mVecVowels.push_back(L'Ò');
    mVecVowels.push_back(L'Ó');
    mVecVowels.push_back(L'Ô');
    mVecVowels.push_back(L'Õ');
    mVecVowels.push_back(L'Ö');
    mVecVowels.push_back(L'Œ');
    mVecVowels.push_back(L'Ø');
    mVecVowels.push_back(L'Ō');
    //Ò Ó Ô Õ Ö Œ Ø Ō
    mVecVowels.push_back(L'U');
    mVecVowels.push_back(L'Ù');
    mVecVowels.push_back(L'Ú');
    mVecVowels.push_back(L'Û');
    mVecVowels.push_back(L'Ü');
    mVecVowels.push_back(L'Ů');
    mVecVowels.push_back(L'Ű');
    //Ù Ú Û Ü Ů Ű
    mVecVowels.push_back(L'Y');
    mVecVowels.push_back(L'Ý');
    mVecVowels.push_back(L'Ÿ');
    //Ý Ÿ
    sort(mVecVowels.begin(), mVecVowels.end());



    mMapSoundex[L'B'] = L'1';
    mMapSoundex[L'F'] = L'1';
    mMapSoundex[L'P'] = L'1';
    mMapSoundex[L'V'] = L'1';
    mMapSoundex[L'C'] = L'2';
    //Ç Č Ć
    mMapSoundex[L'Ç'] = L'2';
    mMapSoundex[L'Č'] = L'2';
    mMapSoundex[L'Ć'] = L'2';

    mMapSoundex[L'G'] = L'2';
    //Ğ
    mMapSoundex[L'Ğ'] = L'2';

    mMapSoundex[L'J'] = L'2';
    mMapSoundex[L'K'] = L'2';
    mMapSoundex[L'Q'] = L'2';
    mMapSoundex[L'S'] = L'2';
    //Ș Š Ş Ś
    mMapSoundex[L'Ș'] = L'2';
    mMapSoundex[L'Š'] = L'2';
    mMapSoundex[L'Ş'] = L'2';
    mMapSoundex[L'Ś'] = L'2';

    mMapSoundex[L'X'] = L'2';
    mMapSoundex[L'Z'] = L'2';
    //Ź Ż Ž
    mMapSoundex[L'Ź'] = L'2';
    mMapSoundex[L'Ż'] = L'2';
    mMapSoundex[L'Ž'] = L'2';

    mMapSoundex[L'D'] = L'3';
    //Ď
    mMapSoundex[L'Ď'] = L'3';

    mMapSoundex[L'T'] = L'3';
    //Ť Ț Ţ
    mMapSoundex[L'Ť'] = L'3';
    mMapSoundex[L'Ț'] = L'3';
    mMapSoundex[L'Ţ'] = L'3';

    mMapSoundex[L'L'] = L'4';
    //Ĺ Ľ Ł
    mMapSoundex[L'Ĺ'] = L'4';
    mMapSoundex[L'Ľ'] = L'4';
    mMapSoundex[L'Ł'] = L'4';

    mMapSoundex[L'M'] = L'5';
    mMapSoundex[L'N'] = L'5';
    //Ñ Ň Ń
    mMapSoundex[L'Ñ'] = L'5';
    mMapSoundex[L'Ň'] = L'5';
    mMapSoundex[L'Ń'] = L'5';

    mMapSoundex[L'R'] = L'6';
    //Ŕ Ř
    mMapSoundex[L'Ŕ'] = L'6';
    mMapSoundex[L'Ř'] = L'6';
}

Latin::~Latin(){

}

const bool Latin::isExistVowel(const wchar_t wc) {
    return binary_search(mVecVowels.begin(), mVecVowels.end(), wc);
}


const vector<wchar_t> *Latin::getVowels() {
    return &mVecVowels;
}

const map<wchar_t, wchar_t> *Latin::getSoundexMap() {
    return &mMapSoundex;
};