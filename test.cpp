#include "translate.hpp"
#include "translateTables.hpp"
#include <iostream>

int main() {
        ILang* lang = new EnglishLang();
        EnglishTranslit transliter(lang);
    
        std::vector<std::string> examples = {
        "esli",
         "uznaesh`",
        "uznayosh`",
        "shhitka",
    };
        for (auto i: examples) {
            std::cout << i << " === " << transliter.translitString(i) << std::endl;
        }
    
    return 0;
}