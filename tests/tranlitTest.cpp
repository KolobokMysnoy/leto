#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "translate.hpp"
#include "translateTables.hpp"
#include "englishTable.hpp"
#include "russianTable.hpp"

// Hard strings from GOST
TEST(EnglishToRussian, HardStrings) {
    // Выудить было убрано, так как транслитерация правильная может быть как выудить,
    // так и вюдить.
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
        // "vyudit`",
        "novye",
        "opyat`",
        "cifra",
        "me`r",
        "shhit",
        "schitka",
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
        // "выудить",
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

TEST(EnglishToRussian, Text) {
    std::string EnglistText = "Translit (sokrashhenno ot «transliteraciya») — e`to napisanie slov odnogo yazyka bukvami drugogo. Kak pravilo, translitom nazyvayut kirillicheskij tekst, napisannyj latinskimi bukvami. Naprimer, vopros Kak perevesti russkij v translit? mozhet byt` napisan Kak perevesti russkij v translit?";
    std::string expectedRussian = "Транслит (сокращенно от «транслитерация») — это написание слов одного языка буквами другого. Как правило, транслитом называют кириллический текст, написанный латинскими буквами. Например, вопрос Как перевести русский в транслит? может быть написан Как перевести русский в транслит?";

    ILang* lang = new EnglishLang();
    EnglishTranslit transliter(lang);

    EXPECT_EQ(
        transliter.translitString(EnglistText),
        expectedRussian
    );
};

TEST(RussianToEnglish, Hard) {
std::vector<std::string> expectedResults = {
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
        // "vyudit`",
        "novye",
        "opyat`",
        "cifra",
        "me`r",
        "shhit",
        "schitka",
    };
    
    std::vector<std::string> examples = {
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
        // "выудить",
        "новые",
        "опять",
        "цифра",
        "мэр",
        "щит",
        "считка",
    };

    ILang* lang = new RussianLang();
    RussianTranslit transliter(lang);

    for(int i = 0; i < examples.size(); i++) {
        EXPECT_EQ(
            transliter.translitString(examples[i]),
            expectedResults[i]
        );
    }
};

TEST(RussianToEnglish, Text) {
    std::string expected = "Translit (sokrashhenno ot «transliteraciya») — e`to napisanie slov odnogo yazyka bukvami drugogo. Kak pravilo, translitom nazyvayut kirillicheskij tekst, napisannyj latinskimi bukvami. Naprimer, vopros Kak perevesti russkij v translit? mozhet byt` napisan Kak perevesti russkij v translit?";
    std::string russianText = "Транслит (сокращенно от «транслитерация») — это написание слов одного языка буквами другого. Как правило, транслитом называют кириллический текст, написанный латинскими буквами. Например, вопрос Как перевести русский в транслит? может быть написан Как перевести русский в транслит?";

    ILang* lang = new RussianLang();
    RussianTranslit transliter(lang);

    EXPECT_EQ(
        transliter.translitString(russianText),
        expected
    );
};
