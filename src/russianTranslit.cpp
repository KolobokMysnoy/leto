#include "translate.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "converter.hpp"

/// @brief Set language that will translit
/// @param languageTranslite 
RussianTranslit::RussianTranslit(ILang *languageTranslite)
{
    changeTable(languageTranslite);
}

/// @brief Translit string to string in another language 
/// @param toTranslit String to translit
/// @return Translited string
std::string RussianTranslit::translitString(const std::string toTranslit)
{
    std::string replacementString = "";
    std::string currentStringToReplace = "";
    
    ConverterString converter;
    std::wstring utf16ToTranslit = converter.utf8_to_wstring(toTranslit);

    int i = 0;
    while (i < utf16ToTranslit.size()) {
        std::string replacementSubstr;
        replacementSubstr = converter.wstring_to_utf8(utf16ToTranslit.substr(i,1));

        if (languageTranslit->isInReplacementTable(replacementSubstr))
        {
            replacementString += languageTranslit->getReplaceNow(
                replacementSubstr
                );
        } else {
            replacementString += replacementSubstr;
        };
        i++;
    }
    return replacementString;
}

/// @brief Change language that translit
/// @param languageTranslite language that will translit symbols 
void RussianTranslit::changeTable(ILang *languageTranslite)
{
    this->languageTranslit = languageTranslite;
}
