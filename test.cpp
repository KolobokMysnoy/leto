#include "translate.hpp"
#include "translateTables.hpp"
#include <iostream>

int main() {
        ILang* lang = new EnglishLang();
        EnglishTranslit transliter(lang);
    
        std::vector<std::string> toConvert = {
            // "privet mir! ch",
            // "yolka",
            "YOlka",
            "ob``em",
            "uznaesh"
        };

        for (auto i: toConvert) {
            std::cout << i << " === " << transliter.translitString(i) << std::endl;
        }
        // std::string testString = "privet mir! ch";
        // std::cout << testString << "| Was translited to |:\n " 
        //     << transliter.translitString(testString) << std::endl;
        // std::cout << testString << "| Was translited to |:\n " 
        //     << transliter.translitString("yolka") << std::endl;
        // std::cout << testString << "| Was translited to |:\n " 
        //     << transliter.translitString("ob``em") << std::endl;
        // std::cout << testString << "| Was translited to |:\n " 
        //     << transliter.translitString("uznaesh`") << std::endl;
    
    return 0;
}