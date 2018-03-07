#include <cwctype>
#include <algorithm>
#include <locale>
#include <iostream>
#include <codecvt>
#include "Soundex.h"

Soundex::Soundex() {
    mSoundexTableFactory = new SoundexTableFactory();
}


Soundex::~Soundex() {
    if (mSoundexTableFactory != nullptr)
        delete mSoundexTableFactory;
}

string Soundex::encode(const string &word, const int localeType){
    setlocale(LC_ALL,""); // default locale -> Unicode locale.
    mSoundexTable = mSoundexTableFactory->getSoundexTable(localeType);
    wstring wstr = utf8ToWstring(word);
    wstring encoded = encodeString(wstr);
    string str = wstringToUtf8(encoded);
    return str;
}

string Soundex::encode(const wstring &word, const int localeType) {
    setlocale(LC_ALL,""); // default locale -> Unicode locale.
    mSoundexTable = mSoundexTableFactory->getSoundexTable(localeType);
    wstring encoded = encodeString(word);
    string str = wstringToUtf8(encoded);
    return str;
}


wstring Soundex::encodeString(const wstring &word) {
    wstring encoded = wstring(1, towupper(word[0]));
    wchar_t prevChar = 0;
    wstring prevEncoding = encodeChar(encoded[0]);

    for (int i = 1; i < word.length(); i++) {
        wchar_t c = towupper(word[i]);
        wstring nextEncoding = encodeChar(c);

        if (nextEncoding != L"" && (isVowel(prevChar) || nextEncoding != prevEncoding)) {
            encoded += nextEncoding;
            prevEncoding = nextEncoding;
        }
        prevChar = c;
    }
    return encoded;
}

wstring Soundex::encodeChar(const wchar_t &c) {
    const map<wchar_t, wchar_t>* soundexMap = mSoundexTable->getSoundexMap();
    const map<wchar_t, wchar_t>::const_iterator it = soundexMap->find(c);
    if (it != soundexMap->end()) {
        return wstring(1, it->second);
    }
    return L"";
}


bool Soundex::isVowel(const wchar_t &c) {
    return mSoundexTable->isExistVowel(c);
}


string Soundex::wstringToUtf8(const std::wstring& str){
    std::wstring_convert<std::codecvt_utf8<wchar_t> > strCnv;
    return strCnv.to_bytes(str);
}

wstring Soundex::utf8ToWstring(const std::string& str){
    std::wstring_convert< std::codecvt_utf8<wchar_t> > strCnv;
    return strCnv.from_bytes(str);
}