#include "converter.hpp"

std::wstring ConverterString::utf8_to_wstring(const std::string &utf8_string)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(utf8_string);
};

std::string ConverterString::wstring_to_utf8(const std::wstring &wstring)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstring);
};