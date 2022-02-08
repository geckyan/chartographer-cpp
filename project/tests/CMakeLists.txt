cmake_minimum_required(VERSION 3.19)
project(tests)

include("Utilities")

add_executable(${PROJECT_NAME})
setup_charta_target(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        core
        CONAN_PKG::catch2
)
