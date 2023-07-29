#include "transformer.hpp"
#include <algorithm>
#include <locale>
#include <codecvt>

RussianTransform::RussianTransform()
{
}

/// @brief Transform string of russian letters to upper capitals
std::string RussianTransform::transformToUpper(const std::string whatTransform)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::wstring wstr = converter.from_bytes(whatTransform);

    std::locale loc("ru_RU.UTF-8");
    for (wchar_t& c : wstr) {
        c = std::toupper(c, loc);
    }

    return converter.to_bytes(wstr);
}

/// @brief Transform string of russian letters to lower capitals
std::string RussianTransform::transformToLower(const std::string whatTransform)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::wstring wstr = converter.from_bytes(whatTransform);

    std::locale loc("ru_RU.UTF-8");
    for (wchar_t& c : wstr) {
        c = std::tolower(c, loc);
    }

    return converter.to_bytes(wstr);
}

EnglishTransform::EnglishTransform()
{
}

/// @brief Transform string of english letters to upper capitals
std::string EnglishTransform::transformToUpper(const std::string whatTransform)
{
    std::string upperString = whatTransform;
    if (whatTransform.size() == 1) {
        upperString = toupper(whatTransform[0]);
    } else {
        std::transform(
            upperString.begin(),
            upperString.end(),
            upperString.begin(),
            ::toupper
            );
    }
    return upperString;
}

/// @brief Transform string of english letters to lower capitals 
std::string EnglishTransform::transformToLower(const std::string whatTransform)
{
    std::string lowerString = whatTransform;
    if (whatTransform.size() == 1) {
        lowerString = tolower(whatTransform[0]);
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
