cmake_minimum_required(VERSION 4.1)
project(mini_db)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(mini_db src/main.cpp
        include/parser/command.hpp
        src/parser/command_parser.cpp
        include/parser/command_parser.hpp
        include/storage/kv_store.hpp
        src/storage/kv_store.cpp
        include/storage/value.hpp
        include/storage/string_value.hpp
        src/storage/string_value.cpp
        src/storage/list_value.cpp
        include/storage/list_value.hpp
)

target_include_directories(mini_db PRIVATE include)

# Enable compiler warnings (portable across MSVC / GCC / Clang)
target_compile_options(mini_db PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)

# Optional: treat warnings as errors (toggle ON when you want stricter builds)
option(MINI_DB_WERROR "Treat warnings as errors" OFF)
if (MINI_DB_WERROR)
    target_compile_options(mini_db PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Werror>
    )
endif()
