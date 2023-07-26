#include "translateTables.hpp"
#include <algorithm>
#include <locale>
#include <codecvt>

EnglishLang::EnglishLang()
{
    russianTable = russianTb;
    englishTable = englishTb;
}

int EnglishLang::countMatches(std::string whatCount)
{
    return searchForCount(lowerString(whatCount));
}

bool EnglishLang::isSingleMatch(std::string whatSearch)
{
    return searchForCount(lowerString(whatSearch), 2) == 1;
}


/// @brief If whatCheck exists in the table one to one function will return True
/// @param whatCheck String to be searched in the table
/// @return True if string exist in table
bool EnglishLang::isInReplaceTable(std::string whatCheck)
{
    for(auto replacement: englishTb) {
        if (whatCheck == replacement) {
            return true;
        }
    }
    return false;
}

std::string EnglishLang::searchForReplaceSymbol(std::string whatSearch)
{
    std::string notSensitive = whatSearch;
    std::transform(
        notSensitive.begin(), 
        notSensitive.end(), 
        notSensitive.begin(), 
        ::tolower);

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

    return getReplaceSensitive(russianTable[position], whatSearch);
}


/// @brief Get exact match if exist
std::string EnglishLang::exactMatch(std::string whatToMatch)
{
        std::string notSensitive = whatToMatch;
    std::transform(
        notSensitive.begin(), 
        notSensitive.end(), 
        notSensitive.begin(), 
        ::tolower);

    
    int position = -1;
    for(int i = 0; i < englishTable.size(); i++) {
        if (englishTable[i] == notSensitive) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        return "";
    }

    return getReplaceSensitive(russianTable[position], whatToMatch);

}

std::string EnglishLang::whatReplacement(std::string whatToReplace, int whatPos)
{
    return std::string();
};

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

/// @brief Check if letters was in lowercase or uppercase and return same lowercase or uppercase replacement
/// @param replace replacement letters
/// @param original original letters that was replaced
/// @return string to replace
std::string EnglishLang::getReplaceSensitive(std::string replace, std::string original)
{
    std::string caseSensitiveReplace = replace;
    if (isupper(original[0])) {
        caseSensitiveReplace = this->upperStringRus(caseSensitiveReplace);
    }
    return caseSensitiveReplace;
}


/// @brief Lower entire string of English letters
std::string EnglishLang::lowerStringEng(std::string whatLower)
{
    std::string lowerString = whatLower;
    if (whatLower.size() == 1) {
        lowerString = tolower(whatLower[0]);
    } else {
        std::transform(
            lowerString.begin(),
            lowerString.end(),
            lowerString.begin(),
            ::tolower
            );
    }
    return lowerString;
}

std::string EnglishLang::upperStringRus(std::string whatUpper)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::wstring wstr = converter.from_bytes(whatUpper);

    std::locale loc("ru_RU.UTF-8");
    for (wchar_t& c : wstr) {
        c = std::toupper(c, loc);
    }

    return converter.to_bytes(wstr);
}