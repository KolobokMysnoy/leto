#include "translateTables.hpp"
#include <algorithm>
#include <locale>
#include <codecvt>

EnglishLang::EnglishLang()
{
    russianTable = russianTb;
    englishTable = englishTb;

    russianTransfrom = new RussianTransform();
    englishTransfrom = new EnglishTransform();
    
}

/// @brief Count all matches in replace table
int EnglishLang::countMatches(std::string whatCount)
{
    return searchForCount(englishTransfrom->transformToLower(whatCount));
}

std::string EnglishLang::searchForReplacement(std::string whatToReplace, int positionOfFound)
{
    std::string notSensitive = englishTransfrom->transformToLower(whatToReplace);

    int count = searchForCount(notSensitive, 2);
    if (count == 0 || count > 1) {
        return "";
    }

    int position = -1;
    for(int i = 0; i < englishTable.size(); i++) {
        if (englishTable[i] == notSensitive) {
            position = i;
            break;
        }
    }

    return searchForSensitive(russianTable[position], whatToReplace);
}

std::string EnglishLang::searchForSensitive(std::string replace, std::string original)
{
    std::string caseSensitiveReplace = replace;
    if (isupper(original[0])) {
        caseSensitiveReplace = russianTransfrom->transformToUpper(caseSensitiveReplace);
    }
    return caseSensitiveReplace;
}

std::string EnglishLang::getReplaceNow(const std::string whatReplace)
{
    std::string notSensitive = englishTransfrom->transformToLower(whatToReplace);

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
    
    return searchForSensitive(russianTable[position], whatToReplace);
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
