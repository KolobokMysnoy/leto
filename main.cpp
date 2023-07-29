#include "translate.hpp"
#include "translateTables.hpp"
#include <iostream>
#include "englishTable.hpp"
#include "russianTable.hpp"

int main() {
        ILang* lang = new RussianLang();
        RussianTranslit transliter(lang);
    
        std::vector<std::string> examples = {
        // "esli",
        // "yolka",
        // "ob``em",
        // "ob``yom",
        // "uznaesh`",
        // "uznayosh`",
        // "Chajkovskij",
        // "chaj",
        // "zajka",
        // "jogurt",
        // "major",
        // "rajon",
        // "vwudit`",
        // "novwe",
        // "opyat`",
        // "czifra",
        // "me`r",
        // "shhit",
        // "schitka",
        // "Translit (sokrashhenno ot «transliteraciya») — e`to napisanie slov odnogo yazyka bukvami drugogo. Kak pravilo, translitom nazyvayut kirillicheskij tekst, napisannyj latinskimi bukvami. Naprimer, vopros Kak perevesti russkij v translit? mozhet byt` napisan Kak perevesti russkij v translit?"
        // "если",
        // "ёлка",
        // "объем",
        // "объём",
        // "узнаешь",
        // "узнаёшь",
        // "Чайковский",
        // "чай",
        // "зайка",
        // "йогурт",
        // "майор",
        // "район",
        // "выудить",
        // "новые",
        // "опять",
        // "цифра",
        // "мэр",
        // "щит",
        // "считка",
        "Транслит (сокращенно от «транслитерация») — это написание слов одного языка буквами другого. Как правило, транслитом называют кириллический текст, написанный латинскими буквами. Например, вопрос Как перевести русский в транслит? может быть написан Как перевести русский в транслит?"
        // " транслит?"
    };

// todo в русском 2 индекс на один символ
        for (auto i: examples) {
            std::cout << i << " === \n" << transliter.translitString(i) << std::endl;
        }
    
    return 0;
}