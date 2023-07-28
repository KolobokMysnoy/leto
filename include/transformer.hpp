#ifndef TRANSFORMER
#define TRANSFORMER
#include <string>

class ITrans {
    public:
        virtual std::string transformToLower(const std::string whatTransform) = 0;
        virtual std::string transformToUpper(const std::string whatTransform) = 0;
};

class EnglishTransform: public ITrans {
    public:
        EnglishTransform();

        virtual std::string transformToUpper(const std::string whatTransform) override;
        virtual std::string transformToLower(const std::string whatTransform) override;
};

class RussianTransform: public ITrans {
    public:
        RussianTransform();

        virtual std::string transformToUpper(const std::string whatTransform) override;
        virtual std::string transformToLower(const std::string whatTransform) override;
};

#endif
