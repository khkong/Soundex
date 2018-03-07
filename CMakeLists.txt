cmake_minimum_required(VERSION 3.9)
project(Soundex)

set(CMAKE_CXX_STANDARD 11)

add_executable(Soundex main.cpp Soundex.cpp Soundex.h soundex_table/ISoundexTable.h soundex_table/SoundexTableFactory.hpp soundex_table/Global.h soundex_table/lang/Latin.h soundex_table/lang/Cyrillic.h soundex_table/lang/Latin.cpp soundex_table/lang/Cyrillic.cpp)
