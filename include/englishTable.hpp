#ifndef ENGLISH_TB
#define ENGLISH_TB

#include "translateTables.hpp"

class EnglishLang: public ILang {
    public:
        EnglishLang();

        int countMatches(std::string whatCount) override;
      
        std::string searchForReplacement(std::string whatToReplace, 
            int positionOfFound = 0) override;
        std::string searchForSensitive(std::string replace, 
            std::string original) override;

        std::string getReplaceNow(const std::string whatReplace) override;
        
        bool isInReplacementTable(const std::string whatToCheck) override;

    private:
        std::vector<std::string> russianTable;
        std::vector<std::string> englishTable;
        
        ITrans* russianTransfrom;
        ITrans* englishTransfrom;

        std::string allSymbols;

        int searchForCount(std::string whatSearch, int maxCount = -1);
};

#endif
