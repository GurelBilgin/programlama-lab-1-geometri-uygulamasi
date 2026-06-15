cmake_minimum_required(VERSION 3.16)

project(programlama_lab_1_geometri_uygulamasi
    VERSION 1.0.0
    DESCRIPTION "Programlama Lab 1 Odev 3 - C++ geometri siniflari"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(geometri_lib
    src/Nokta.cpp
    src/DogruParcasi.cpp
    src/Daire.cpp
    src/Ucgen.cpp
)

target_include_directories(geometri_lib PUBLIC include)

add_executable(geometri_uygulamasi src/main.cpp)
target_link_libraries(geometri_uygulamasi PRIVATE geometri_lib)

add_executable(geometri_testleri tests/test_geometri.cpp)
target_link_libraries(geometri_testleri PRIVATE geometri_lib)

enable_testing()
add_test(NAME geometri_testleri COMMAND geometri_testleri)
