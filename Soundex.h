#ifndef WORD_CORRECTION_UTILS_SOUNDEXEN_H_
#define WORD_CORRECTION_UTILS_SOUNDEXEN_H_

#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <wctype.h>
#include "soundex_table/SoundexTableFactory.hpp"
using namespace std;

/**
 * Soundex encoding class.
 * This class can be used to encode American English names into phonetically compareable strings.
 * For example, the names 'Rupert' and 'Robert' will be encoded to the same phonetically independent string since their pronunciations are very similar.
 */

class Soundex{
private :
    static Soundex* mInstance;
    SoundexTableFactory* mSoundexTableFactory;
    ISoundexTable* mSoundexTable;

public:
    Soundex();
    ~Soundex();
    static Soundex* getInstance(){
        return mInstance;
    }

    /**
     * Encode the provided string.
     * The provided string is turned into a four character code.
     * @param word A constant string.
     * @result The encoded string.
     */
    string encode(const string &word, const int localeType);
    string encode(const wstring &word, const int localeType);

private:
    /**
     * Encode an string with the soundex algorithm.
     * @param word A constant string.
     * @result An encoded string.
     */
    wstring encodeString(const wstring &word);

    /**
     * Get the encoded value for a single character.
     * @param c Character to encode.
     * @result String of the encoded character.
     */
    wstring encodeChar(const wchar_t &c);


    /**
     * Check if a character is a vowel.
     * @param c Character to check.
     * @result True if vowel, false otherwise.
     */
    bool isVowel(const wchar_t &c);

    string wstringToUtf8(const std::wstring& str);
    wstring utf8ToWstring(const std::string& str);
};


#endif //SOUNDEX_H