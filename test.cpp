#include "translate.hpp"
#include "translateTables.hpp"
#include <iostream>

int main() {
        ILang* lang = new EnglishLang();
        EnglishTranslit transliter(lang);
    
        std::vector<std::string> toConvert = {
            "privet mir! ch",
            "yolka",
            "YOlka",
            "ob``em",
            "uznaesh"
        };

        for (auto i: toConvert) {
            std::cout << i << " === " << transliter.translitString(i) << std::endl;
        }
    
    return 0;
}