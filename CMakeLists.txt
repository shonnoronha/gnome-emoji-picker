cmake_minimum_required(VERSION 3.14)
project(EmojiPicker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)
find_package(nlohmann_json REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(KEYBINDER REQUIRED keybinder-3.0)
pkg_check_modules(X11 REQUIRED x11)
pkg_check_modules(XTST REQUIRED xtst)


set(SRC_FILES
    src/main.cpp
    src/emoji_picker.cpp
    src/emoji_loader.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${GTKMM_INCLUDE_DIRS}
    ${KEYBINDER_INCLUDE_DIRS}
    ${X11_INCLUDE_DIRS}
    ${XTST_INCLUDE_DIRS}
)

link_directories(
    ${GTKMM_LIBRARY_DIRS}
    ${X11_LIBRARY_DIRS}
    ${XTST_LIBRARY_DIRS}
    ${KEYBINDER_LIBRARY_DIRS}
)

add_executable(emoji_picker ${SRC_FILES})

target_link_libraries(emoji_picker PRIVATE 
    ${GTKMM_LIBRARIES}
    nlohmann_json::nlohmann_json
    ${KEYBINDER_LIBRARIES}
    ${X11_LIBRARIES}
    ${XTST_LIBRARIES}
    X11
    Xtst
)

target_compile_options(emoji_picker PRIVATE 
    ${GTKMM_CFLAGS_OTHER}
    ${X11_CFLAGS_OTHER}
    ${XTST_CFLAGS_OTHER}
    ${KEYBINDER_CFLAGS_OTHER}
)

install(TARGETS emoji_picker DESTINATION bin)
install(FILES assets/emojis.json DESTINATION bin/assets)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(WRITE ${CMAKE_BINARY_DIR}/compile_flags.txt "-std=c++17\n")

