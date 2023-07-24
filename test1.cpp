#include <iostream>
#include <map>
#include <string>
#include <locale> 
#include <algorithm>
#include <codecvt>


// std::string transofrmString(std::string a) {
//     std::locale loc("ru_RU.UTF-8");

//     std::string result;
//     for(auto i: a) {
//         result += toupper(i, loc);
//     }
//     return result;
// }

std::string transformString(const std::string& input) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::wstring wstr = converter.from_bytes(input);

    std::locale loc("ru_RU.UTF-8");
    for (wchar_t& c : wstr) {
        c = std::toupper(c, loc);
    }

    return converter.to_bytes(wstr);
}

int main() {
    std::string b = "привет мир";
    std::locale loc("ru_RU.UTF-8");

    std::cout << b << std::endl;
    b = transformString(b);

    std::cout << b << std::endl;

    return 0;
}
