cmake_minimum_required(VERSION 3.12)
project(my_project)

include_directories(include)

add_executable(main main.cpp)

add_library(translate src/englishTranslit.cpp src/russianTranslit.cpp)
add_library(translateTables src/englishTables.cpp src/russianTable.cpp)
add_library(Transform src/transformer.cpp)
add_library(Converter src/converter.cpp)

target_link_libraries(main translate translateTables Transform Converter)

add_subdirectory(tests)
