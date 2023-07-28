#include "translate.hpp"
#include "translateTables.hpp"
#include <iostream>

int main() {
        ILang* lang = new EnglishLang();
        EnglishTranslit transliter(lang);
    
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
        "Translit (sokrashhenno ot «transliteraciya») — e`to napisanie slov odnogo yazyka bukvami drugogo. Kak pravilo, translitom nazyvayut kirillicheskij tekst, napisannyj latinskimi bukvami. Naprimer, vopros Kak perevesti russkij v translit? mozhet byt` napisan Kak perevesti russkij v translit?"
    };

        for (auto i: examples) {
            std::cout << i << " === \n" << transliter.translitString(i) << std::endl;
        }
    
    return 0;
}