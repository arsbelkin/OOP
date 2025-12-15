cmake_minimum_required(VERSION 4.1)
project(StudentDyLib)

set(CMAKE_CXX_STANDARD 23)

if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    set(CMAKE_OSX_ARCHITECTURES "arm64")
endif()

execute_process(
        COMMAND brew --prefix boost
        OUTPUT_VARIABLE BOOST_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

if("${BOOST_PREFIX}" STREQUAL "")
    set(BOOST_PREFIX "/opt/homebrew/opt/boost")
endif()

set(BOOST_ROOT ${BOOST_PREFIX})
set(Boost_NO_SYSTEM_PATHS ON)

find_package(Boost REQUIRED COMPONENTS serialization)

add_library(StudentDyLib SHARED library.cpp
        Student.cpp
        Student.h
        GroupLeader.cpp
        GroupLeader.h
        Group.cpp
        Group.h)

set_target_properties(StudentDyLib PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_include_directories(StudentDyLib
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(StudentDyLib
        PRIVATE
        ${Boost_SERIALIZATION_LIBRARY}
)

if(APPLE)
    # Настройка rpath
    set_target_properties(StudentDyLib PROPERTIES
            INSTALL_RPATH "@loader_path"
            BUILD_WITH_INSTALL_RPATH ON
            MACOSX_RPATH ON
    )

    find_library(BOOST_SERIALIZATION
            NAMES boost_serialization
            PATHS ${Boost_LIBRARY_DIRS}
            NO_DEFAULT_PATH
    )

    if(BOOST_SERIALIZATION)
        target_link_libraries(StudentDyLib PRIVATE ${BOOST_SERIALIZATION})
    endif()
endif()


include_directories(
        /opt/homebrew/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party
)