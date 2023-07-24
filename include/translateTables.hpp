#ifndef TRANSLATE_TB
#define TRANSLATE_TB

#include <vector>
#include <string>

const std::vector<std::string> englishTb = {
        "ya", 
        "yu", "z", "i", "sh", "zh", 
        "j", "yo", "cz", "l", "g", 
        "sch", "``", "s", "x", "k", 
        "d", "n", "b", "e", "a", 
        "`", "m", "v", "o", "ch", 
        "p", "u", "r", "t", "f"
    };

const std::vector<std::string> russianTb = {
        "я", 
        "ю", "з", "и", "ш", "ж", 
        "й", "ё", "ц", "л", "г", 
        "щ", "ъ", "с", "х", "к", 
        "д", "н", "б", "е", "а", 
        "ь", "м", "в", "о", "ч", 
        "п", "у", "р", "т", "ф"
    };

class ILang {
    public:
    virtual std::string searchForReplaceSymbol(std::string whatSearch) = 0;
    virtual int countMatches(std::string whatCount) = 0;
    virtual bool isSingleMatch(std::string whatSearch) = 0;
    virtual bool isInReplaceTable(std::string whatCheck) = 0; 
    virtual std::string exactMatch(std::string whatToMatch) = 0;
};

class EnglishLang: public ILang {
    public:
        EnglishLang();

        int countMatches(std::string whatCount) override;
        bool isSingleMatch(std::string whatSearch) override;
        bool isInReplaceTable(std::string whatCheck) override;

        std::string searchForReplaceSymbol(std::string whatSearch) override;
        std::string exactMatch(std::string whatToMatch) override;
    
    private:
        std::vector<std::string> russianTable;
        std::vector<std::string> englishTable;

        int searchForCount(std::string whatSearch, int maxCount = -1);
        std::string getReplaceSensitive(std::string replace, std::string original);
        
        std::string lowerString(std::string whatLower);
        std::string upperString(std::string whatUpper);
};

#endif