#include "translate.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/// @brief Set language that will translit
/// @param languageTranslite 
EnglishTranslit::EnglishTranslit(ILang *languageTranslite)
{
    changeTable(languageTranslite);
}

/// @brief Translit string to string in another language 
/// @param toTranslit String to translit
/// @return Translited string
std::string EnglishTranslit::translitString(const std::string toTranslit)
{
    std::string replacementString = "";
    std::string currentStringToReplace = "";

    std::string lastReplacement = "";
    int i = 0;
    int lastReplacePos = 0;
    std::string suggestReplacementBefore = "";

    while(i < toTranslit.size()) {
        currentStringToReplace += toTranslit[i];
        int count = languageTranslit->countMatches(currentStringToReplace);
        
        if (count == 1) {
            replacementString += 
                languageTranslit->getReplaceNow(currentStringToReplace);
            
            lastReplacement = currentStringToReplace;
            currentStringToReplace = "";

            lastReplacePos = i;
            suggestReplacementBefore = "";
        };

        if (count > 1) {
            suggestReplacementBefore = languageTranslit
                ->getReplaceNow(currentStringToReplace);
        }

        // Symbols not in table
        if (currentStringToReplace.size() == 1 && 
            !(languageTranslit->isInReplacementTable(
                std::string(1, currentStringToReplace[0])
            )))
        {
            replacementString += currentStringToReplace;
            
            lastReplacement = currentStringToReplace;
            currentStringToReplace = "";
            count = 1;

            lastReplacePos = i;
            suggestReplacementBefore = "";
        }
        
        if (count == 0 
            && suggestReplacementBefore != "") 
        {
            replacementString += suggestReplacementBefore;
            i -= 1;
            suggestReplacementBefore = "";
            count = 1;    
            currentStringToReplace = "";
        }

        // if cant get replacement
        if (count == 0) {
            std::string replaceSymbols = "";

            for (int j = i - lastReplacement.size() - 1;
                j < toTranslit.size(); j++) 
                {
                    replaceSymbols += toTranslit[j];
                    std::string replace = 
                        languageTranslit->getReplaceNow(replaceSymbols);
                    
                    if (replace != "") {
                        replacementString = replacementString
                            .substr(0, replacementString.size() - 1);

                        replacementString += replace;
                        i += -lastReplacement.size() + replace.size();

                        lastReplacement = replaceSymbols;
                        break;
                    }
                }
        }

        i++;
    };


    return replacementString + suggestReplacementBefore;
}

/// @brief Change language that translit
/// @param languageTranslite language that will translit symbols 
void EnglishTranslit::changeTable(ILang *languageTranslite)
{
    this->languageTranslit = languageTranslite;
}
