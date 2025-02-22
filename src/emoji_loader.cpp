#include "emoji_loader.h"
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

