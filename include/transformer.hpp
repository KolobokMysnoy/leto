#pragma once

#include <string>

class ITrans {
    public:
        virtual std::string transformToLower(const std::string whatTransform) = 0;
        virtual std::string transformToUpper(const std::string whatTransform) = 0;
};

class EnglishTransform: public ITrans {
    public:
        std::string transformToUpper(const std::string whatTransform) override;
        std::string transformToLower(const std::string whatTransform) override;
};

class RussianTransform: public ITrans {
    public:
        std::string transformToUpper(const std::string whatTransform) override;
        std::string transformToLower(const std::string whatTransform) override;
};
