#include <iostream>
#include <string>

#include "translate.hpp"
#include "translateTables.hpp"
#include "englishTable.hpp"
#include "russianTable.hpp"

int main() {
        std::cout << "Choose language:" << std::endl << "1) English" << std::endl << "2) Russian" << std::endl;
        
        std::string inputString;
        int userChoose = 0;
        std::cin >> userChoose;
        
        std::cout << "Input string:" << std::endl;
        std::getline(std::cin, inputString);
        std::getline(std::cin, inputString);
        
        ITranslit* transliter;
        switch (userChoose)
        {
        case 1:
            {
                ILang* lang = new EnglishLang();
                transliter = new EnglishTranslit(lang);
                break;
            }
        case 2:
            {
                ILang* lang = new RussianLang();
                transliter = new RussianTranslit(lang);
                break;
            }
        default:
            std::cout << "Wrong language" << std::endl;
            break;
        }
        std::cout << transliter->translitString(inputString);
    
    return 0;
}