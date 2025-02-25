#include "emoji_loader.h"
#include <cstdlib>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

std::vector<std::string> load_emojis_from_file(const std::string& filename) {
    std::vector<std::string> emojis;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open emoji file!" << std::endl;
        return emojis;
    }

    nlohmann::json json_data;
    file >> json_data;

    if (json_data.contains("emojis") && json_data["emojis"].is_array()) {
        for (const auto& emoji : json_data["emojis"]) {
            emojis.push_back(emoji.get<std::string>());
        }
    }

    return emojis;
}


std::string get_emoji_file_path() {
    const char* xdg_data_home = getenv("XDG_DATA_HOME");
    std::vector<std::string> search_paths = {
        "assets/emojis.json",
        "/usr/local/share/emoji-picker/emojis.json"
    };

    for (const auto& path : search_paths) {
        if (std::filesystem::exists(path)) {
            return path;
        }
    }

    throw std::runtime_error("Could not find emojis.json");
}
