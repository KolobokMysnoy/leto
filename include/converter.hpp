#ifndef CONVERTER
#define CONVERTER

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

class IConverter {
    public:
        virtual std::wstring utf8_to_wstring(const std::string& utf8_string) = 0; 
        virtual std::string wstring_to_utf8(const std::wstring& wstring) = 0;
};

class ConverterString: public IConverter {
    public:
        std::wstring utf8_to_wstring(const std::string& utf8_string) override; 
        std::string wstring_to_utf8(const std::wstring& wstring) override;
};

#endif