cmake_minimum_required(VERSION 3.14)
project(EmojiPicker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find GTKMM
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Find nlohmann/json installed via package manager
find_package(nlohmann_json REQUIRED)

# Set source files
set(SRC_FILES
    src/main.cpp
    src/emoji_picker.cpp
    src/emoji_loader.cpp
)

# Include directories
include_directories(${GTKMM_INCLUDE_DIRS} include)
add_executable(emoji_picker ${SRC_FILES})

# Link libraries
target_link_libraries(emoji_picker PRIVATE ${GTKMM_LIBRARIES} nlohmann_json::nlohmann_json)
target_compile_options(emoji_picker PRIVATE ${GTKMM_CFLAGS_OTHER})

# Install target
install(TARGETS emoji_picker DESTINATION bin)
install(FILES assets/emojis.json DESTINATION bin/assets)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add compile_flags.txt (if needed)
file(WRITE ${CMAKE_BINARY_DIR}/compile_flags.txt "-std=c++17\n")

