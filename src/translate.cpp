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
    bool existBefore = false;
    std::string beforeReplacement = "";

    for(int i = 0; i < toTranslit.length(); i++) {
        symbol += toTranslit[i];
        std::string replacement = 
            languageTranslit->searchForReplaceSymbol(symbol);
        
        int matches = languageTranslit->countMatches(symbol);

        if (replacement == "" && matches == 0) {
            if (beforeReplacement != "") {
                replacement = beforeReplacement;
                
                char lastChar = symbol[symbol.size() - 1];
                std::string tmp;
                tmp.push_back(lastChar);

                std::string replacementAdd = 
                    languageTranslit->searchForReplaceSymbol(tmp);

                replacement += replacementAdd;
            } else {
                replacement = symbol;
            }
        }

        if (matches > 0) {
            existBefore = true;
            beforeReplacement = languageTranslit->exactMatch(symbol);
        }
        
        if (replacement != "") {
            symbol = "";
            existBefore = false;
            beforeReplacement = "";
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
