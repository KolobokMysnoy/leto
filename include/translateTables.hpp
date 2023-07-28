#ifndef TRANSLATE_TB
#define TRANSLATE_TB

#include <vector>
#include <string>
#include "transformer.hpp"

const std::vector<std::string> englishTb = {
        "ya", "w", "e`",
        "yu", "z", "i", "sh", "zh", 
        "j", "yo", "cz", "l", "g", 
        "shh", "``", "s", "x", "k", 
        "d", "n", "b", "e", "a", 
        "`", "m", "v", "o", "ch", 
        "p", "u", "r", "t", "f"
    };

const std::vector<std::string> russianTb = {
        "я", "ы", "э",
        "ю", "з", "и", "ш", "ж", 
        "й", "ё", "ц", "л", "г", 
        "щ", "ъ", "с", "х", "к", 
        "д", "н", "б", "е", "а", 
        "ь", "м", "в", "о", "ч", 
        "п", "у", "р", "т", "ф"
    };


class ILang {
    public:
        virtual int countMatches(std::string whatToSearch) = 0;
        
        virtual std::string searchForReplacement(std::string whatToReplace, 
            int positionOfFound = 0) = 0;
        virtual std::string searchForSensitive(std::string replace,
            std::string original) = 0;

        virtual std::string getReplaceNow(const std::string whatReplace) = 0;
};


class EnglishLang: public ILang {
    public:
        EnglishLang();

        int countMatches(std::string whatCount) override;
      
        std::string searchForReplacement(std::string whatToReplace, 
            int positionOfFound = 0);
        std::string searchForSensitive(std::string replace, 
            std::string original);

        std::string getReplaceNow(const std::string whatReplace);

    private:
        std::vector<std::string> russianTable;
        std::vector<std::string> englishTable;
        
        ITrans* russianTransfrom;
        ITrans* englishTransfrom;

        int searchForCount(std::string whatSearch, int maxCount = -1);
};

#endif