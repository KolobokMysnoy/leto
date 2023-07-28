cmake_minimum_required(VERSION 3.12)
project(my_project)

# Указываем путь к заголовочным файлам
include_directories(include)

# Добавляем исполняемый файл main
add_executable(main main.cpp)

# Добавляем библиотеки для module1 и module2
add_library(Transform src/transformer.cpp)
add_library(module1 src/translate.cpp)
add_library(module2 src/translateTables.cpp)

# Линкуем исполняемый файл с библиотеками
target_link_libraries(main module1 module2 Transform)

add_subdirectory(tests)
