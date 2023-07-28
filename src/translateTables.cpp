#include "translateTables.hpp"
#include <algorithm>
#include <locale>
#include <codecvt>
#include "transformer.hpp"

EnglishLang::EnglishLang()
{
    russianTable = russianTb;
    englishTable = englishTb;

    russianTransfrom = new RussianTransform();
    englishTransfrom = new EnglishTransform();

    allSymbols = "";
    // todo optimize for only one symbol
    for (auto i: englishTable) {
        allSymbols += i;
    }
}

/// @brief Count all matches in replace table
int EnglishLang::countMatches(std::string whatCount)
{
    return searchForCount(englishTransfrom->transformToLower(whatCount));
}

/// @brief Get replacement string from string that want to replace
/// @param whatToReplace what string want to replace
/// @param positionOfFound what position in all replacements is need to take
/// @return replacement string or "" if not found
std::string EnglishLang::searchForReplacement(std::string whatToReplace, int positionOfFound)
{
    int count = searchForCount(
        englishTransfrom->transformToLower(whatToReplace),
        2);

    if (count == 0 || count > 1) {
        return "";
    }

    return getReplaceNow(whatToReplace); 
}

/// @brief Get string that sensitive to case
/// @param replace string that replace origin string 
/// @param original origin string that want to replace
/// @return String that case sensitive
std::string EnglishLang::searchForSensitive(std::string replace, std::string original)
{
    std::string caseSensitiveReplace = replace;
    if (isupper(original[0])) {
        caseSensitiveReplace = russianTransfrom->transformToUpper(caseSensitiveReplace);
    }
    return caseSensitiveReplace;
}

/// @brief Get replace of string if it will equal. If not equal return ""
/// @param whatReplace 
/// @return 
std::string EnglishLang::getReplaceNow(const std::string whatReplace)
{
    std::string notSensitive = englishTransfrom->transformToLower(whatReplace);

    int position = -1;
    for(int i = 0; i < englishTable.size(); i++) {
        if (englishTable[i] == notSensitive) {
            position = i;
            break;
        }
    }

    if (position < 0) {
        return "";
    }
    
    return searchForSensitive(russianTable[position], whatReplace);
}

/// @brief Check if symbols is in replacement table
/// @param whatToCheck 
/// @return 
bool EnglishLang::isInReplacementTable(const char whatToCheck)
{
    char notSensitive = 
        englishTransfrom->transformToLower(std::string(1, whatToCheck))[0];
    return allSymbols.find(notSensitive) 
        != std::string::npos;
}

/// @brief Function will be search for count in table and return counts
/// @param whatSearch string to search in table 
/// @param maxCount Maximum count when return. If given -1 it will return all counts
/// @return count of matches if count of matches <= maxCount
int EnglishLang::searchForCount(std::string whatSearch, int maxCount)
{
    bool isSearchAll = false;
    if (maxCount == -1) {
        isSearchAll = true;
    }
    
    int count = 0;
    for(auto i: englishTable) {
        if (i.find(whatSearch) == 0) {
            count++;
            if (!isSearchAll && count > maxCount) {
                return count;
            }
        }
    }
    return count;
}
