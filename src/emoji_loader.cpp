#include "emoji_loader.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

std::vector<EmojiData> load_emojis_from_file(const std::string &filename) {
    std::vector<EmojiData> emojis;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error! : Could not open the emoji file" << std::endl;
        return emojis;
    }
    
    nlohmann::json json_data;
    file >> json_data;

    if (json_data.contains("emojis") && json_data["emojis"].is_array()) {
        std::cout << "Emoji count : " <<  json_data["emojis"].size() << std::endl;
        for (const auto &emoji_json : json_data["emojis"]) {
            EmojiData emoji;
            emoji.emoji = emoji_json["emoji"].get<std::string>();
            emoji.name = emoji_json["name"].get<std::string>();
            emoji.category = emoji_json["category"].get<std::string>();
            emoji.subcategory = emoji_json["subcategory"].get<std::string>();

            if (emoji_json.contains("code") && emoji_json["code"].is_array()) {
                for (const auto &code : emoji_json["code"]) {
                    emoji.codes.push_back(code.get<std::string>());
                }
            }

            emojis.push_back(emoji);
        }
    }
    return emojis;

}

std::string get_emoji_file_path() {
    std::vector<std::string> search_paths = {
        "assets/emojis.json", "/usr/local/share/emoji-picker/emojis.json"};

    for (const auto &path : search_paths) {
        if (std::filesystem::exists(path)) {
            return path;
        }
    }

    throw std::runtime_error("Could not find emojis.json");
}
