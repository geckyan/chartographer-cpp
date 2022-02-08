cmake_minimum_required(VERSION 3.19)
include_guard()

function(get_project_files PROJECT_FILES)
    set(PROJECT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    set(SOURCES_FILES)

    if(${ARGC} EQUAL 2)
        set(PROJECT_DIRECTORY ${ARGV1})
    endif()

    set(GLOB_EXPRS
        ${PROJECT_DIRECTORY}/*.h
        ${PROJECT_DIRECTORY}/*.c
        ${PROJECT_DIRECTORY}/*.hpp
        ${PROJECT_DIRECTORY}/*.cpp
        ${PROJECT_DIRECTORY}/*.inl
    )

    file(GLOB_RECURSE SOURCES_FILES ${GLOB_EXPRS})

    foreach(SOURCE_FILE IN ITEMS ${SOURCES_FILES})
        file(RELATIVE_PATH RELATIVE_SOURCE_FILE_PATH "${PROJECT_DIRECTORY}" "${SOURCE_FILE}")
        get_filename_component(SOURCE_FILE_DIRECTORY "${RELATIVE_SOURCE_FILE_PATH}" DIRECTORY)
        string(REPLACE "/" "\\" SOURCE_FILE_GROUP "${SOURCE_FILE_DIRECTORY}")
        source_group("${SOURCE_FILE_GROUP}" FILES "${SOURCE_FILE}")
    endforeach()

    set(${PROJECT_FILES} ${SOURCES_FILES} PARENT_SCOPE)
endfunction(get_project_files)

function(setup_charta_target TARGET)
    if(MSVC)
        target_compile_options(${TARGET} PRIVATE  "-W3" "/Zc:__cplusplus")
    else()
        target_compile_options(${TARGET} PRIVATE -Wall -Wextra)
    endif()

    target_compile_features(${TARGET} PUBLIC cxx_std_17)

    get_project_files(PROJECT_FILES)
    target_sources(${TARGET} PRIVATE ${PROJECT_FILES})

    target_include_directories(${TARGET}
        PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}/include"
        PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
endfunction()
