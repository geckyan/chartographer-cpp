cmake_minimum_required(VERSION 3.19)
project(core)

include("Utilities")

add_library(${PROJECT_NAME} STATIC)
setup_charta_target(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        CONAN_PKG::stb
        CONAN_PKG::poco
)
