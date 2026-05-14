cmake_minimum_required(VERSION 3.20)
project(Euthymia
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "game dev simulation lab"
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LUA REQUIRED lua5.4 IMPORTED_TARGET)

add_executable(euthymia
    src/main.cpp
)

target_link_libraries(euthymia PRIVATE
    raylib
    PkgConfig::LUA
)
