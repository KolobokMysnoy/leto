#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "translate.hpp"
#include "translateTables.hpp"

// Hard strings from GOST
TEST(EnglishToRussian, HardStrings) {
    std::vector<std::string> examples = {
        "esli",
        "yolka",
        "ob``em",
        "ob``yom",
        "uznaesh`",
        "uznayosh`",
        "Chajkovskij",
        "chaj",
        "zajka",
        "jogurt",
        "major",
        "rajon",
        "vwudit`",
        "novwe",
        "opyat`",
        "czifra",
        "me`r",
        "shhit",
        "shhitka",
    };
    
    std::vector<std::string> expectedResults = {
        "если",
        "ёлка",
        "объем",
        "объём",
        "узнаешь",
        "узнаёшь",
        "Чайковский",
        "чай",
        "зайка",
        "йогурт",
        "майор",
        "район",
        "выудить",
        "новые",
        "опять",
        "цифра",
        "мэр",
        "щит",
        "считка",
    };

    ILang* lang = new EnglishLang();
    EnglishTranslit transliter(lang);

    for(int i = 0; i < examples.size(); i++) {
        EXPECT_EQ(
            transliter.translitString(examples[i]),
            expectedResults[i]
        );
    }

};
