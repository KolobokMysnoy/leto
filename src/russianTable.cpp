#include "russianTable.hpp"
#include <algorithm>
#include <locale>
#include <codecvt>
#include <cwctype>

RussianLang::RussianLang()
{
    russianTable = russianTb;
    englishTable = englishTb;

    russianTransfrom = new RussianTransform();
    englishTransfrom = new EnglishTransform();

    allSymbols = "";
    // todo optimize for only one symbol
    for (auto i: russianTable) {
        allSymbols += i;
    }
}



/// @brief Count all matches in replace table
int RussianLang::countMatches(std::string whatCount)
{
    return searchForCount(russianTransfrom->transformToLower(whatCount));
}

/// @brief Get replacement string from string that want to replace
/// @param whatToReplace what string want to replace
/// @param positionOfFound what position in all replacements is need to take
/// @return replacement string or "" if not found
std::string RussianLang::searchForReplacement(std::string whatToReplace, int positionOfFound)
{
    int count = searchForCount(
        russianTransfrom->transformToLower(whatToReplace),
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
std::string RussianLang::searchForSensitive(std::string replace, std::string original)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> converter;
    std::wstring originalUtf16 = converter.from_bytes(original);

    // todo Think about more common solution
    std::locale loc("ru_RU.UTF-8");

    std::string caseSensitiveReplace = "";
    if (originalUtf16[0] == std::toupper(originalUtf16[0], loc)) {
        caseSensitiveReplace = englishTransfrom->transformToUpper(
            replace.substr(0,1)
        );
        
        caseSensitiveReplace += replace.substr(1,replace.size()-1);
    } else {
        caseSensitiveReplace += replace;
    }
    return caseSensitiveReplace;
}

/// @brief Get replace of string if it will equal. If not equal return ""
/// @param whatReplace 
/// @return 
std::string RussianLang::getReplaceNow(const std::string whatReplace)
{
    std::string notSensitive = russianTransfrom->transformToLower(whatReplace);

    int position = -1;
    for(int i = 0; i < russianTable.size(); i++) {
        if (russianTable[i] == notSensitive) {
            position = i;
            break;
        }
    }

    if (position < 0) {
        return "";
    }
    
    return searchForSensitive(englishTable[position], whatReplace);
}

/// @brief Check if symbols is in replacement table
/// @param whatToCheck 
/// @return 
bool RussianLang::isInReplacementTable(const std::string whatToCheck)
{
    char notSensitive = 
        russianTransfrom->transformToLower(whatToCheck)[0];
    return allSymbols.find(notSensitive) 
        != std::string::npos;
}

/// @brief Function will be search for count in table and return counts
/// @param whatSearch string to search in table 
/// @param maxCount Maximum count when return. If given -1 it will return all counts
/// @return count of matches if count of matches <= maxCount
int RussianLang::searchForCount(std::string whatSearch, int maxCount)
{
    bool isSearchAll = false;
    if (maxCount == -1) {
        isSearchAll = true;
    }
    
    int count = 0;
    for(auto i: russianTable) {
        if (i.find(whatSearch) == 0) {
            count++;
            if (!isSearchAll && count > maxCount) {
                return count;
            }
        }
    }
    return count;
}
