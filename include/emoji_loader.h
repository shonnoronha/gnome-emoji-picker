#ifndef EMOJI_LOADER_H
#define EMOJI_LOADER_H

#include <string>
#include <vector>

struct EmojiData {
    std::string emoji;
    std::string name;
    std::string category;
    std::string subcategory;
    std::vector<std::string> codes;
};

std::vector<EmojiData> load_emojis_from_file(const std::string &filename);
std::string get_emoji_file_path();
#endif
