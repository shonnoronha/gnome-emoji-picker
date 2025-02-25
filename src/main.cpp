#include "emoji_picker.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.emoji_picker");
    EmojiPicker picker;
    app->run(picker);
    return 0;
}

