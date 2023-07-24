#include "translate.hpp"

/// @brief Set language that will translit
/// @param languageTranslite 
EnglishTranslit::EnglishTranslit(ILang *languageTranslite)
{
    changeTable(languageTranslite);
}

/// @brief Translit string to string in another language 
/// @param toTranslit String to translit
/// @return Translited string
std::string EnglishTranslit::translitString(std::string toTranslit)
{
    std::string translitedResult = "";
    std::string symbol = "";

    for(int i = 0; i < toTranslit.length(); i++) {
        symbol += toTranslit[i];
        std::string replacement = 
            languageTranslit->searchForReplaceSymbol(symbol);
        
        if (replacement == "" && languageTranslit->countMatches(symbol) == 0) {
            replacement = symbol;
        }
        
        if (replacement != "") {
            symbol = "";
        }

        translitedResult += replacement;
    }

    return translitedResult;
}

/// @brief Change language that translit
/// @param languageTranslite language that will translit symbols 
void EnglishTranslit::changeTable(ILang *languageTranslite)
{
    this->languageTranslit = languageTranslite;
}
