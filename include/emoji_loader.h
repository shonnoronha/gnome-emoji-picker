#ifndef EMOJI_LOADER_H
#define EMOJI_LOADER_H

#include <string>
#include <vector>

std::vector<std::string> load_emojis_from_file(const std::string &filename);
std::string get_emoji_file_path();
#endif
