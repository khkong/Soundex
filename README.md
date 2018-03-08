# Soundex
You can use soundex of Latin and Cyrillic characters.

## Overview
Soundex is one way to determine the phonological similarity of two strings.

This repository supports soundex for Latin or Cyrillic characters.

## Example
The following shows how to use it.

```
    //example
    Soundex* soundex = new Soundex();
    std::cout << "Россия -> ";
    string encode1 = soundex->encode("Россия", Global::LOCALE_TYPE::RU_RU);
    cout<<encode1<<endl;
    

    std::cout << "Russia -> ";
    string encode2 = soundex->encode(L"Russia", Global::LOCALE_TYPE::EN_US);
    cout<<encode2<<endl;
    delete soundex;
```

The output is shown below.

```
    Россия -> Р2
    Russia -> R2
```


## Reference
1. https://en.wikipedia.org/wiki/Soundex
