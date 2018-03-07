//
// Created by kyeonghwan on 18. 3. 7.
//

#ifndef SOUNDEX_SOUNDEXTABLEFACTORY_H
#define SOUNDEX_SOUNDEXTABLEFACTORY_H

#include "ISoundexTable.h"
#include "Global.h"
#include "lang/Cyrillic.h"
#include "lang/Latin.h"
#include <vector>

class SoundexTableFactory {
public :
    ISoundexTable *getSoundexTable(int locale) {
        if (locale == Global::RU_RU) {
            return Cyrillic::getInstance();
        } else {
            return Latin::getInstance();
        }
    }
};


#endif //SOUNDEX_SOUNDEXTABLEFACTORY_H
