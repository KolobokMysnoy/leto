#ifndef TRANSLATE
#define TRANSLATE
#include "translateTables.hpp"

class ITranslit {
    public:
        virtual std::string translitString(const std::string toTranslit) = 0;
        virtual void changeTable(ILang* languageTranslite) = 0;
};

class EnglishTranslit: public ITranslit {
    public:
        EnglishTranslit(ILang* languageTranslite);

        std::string translitString(const std::string toTranslit) override;
        void changeTable(ILang* languageTranslite) override;
        
    private:
        ILang* languageTranslit;
};

class RussianTranslit: public ITranslit {
    public:
        RussianTranslit(ILang* languageTranslite);

        std::string translitString(const std::string toTranslit) override;
        void changeTable(ILang* languageTranslite) override;
        
    private:
        ILang* languageTranslit;
};

#endif
