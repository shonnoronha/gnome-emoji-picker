#include "emoji_picker_app.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.emoji_picker");
    /*EmojiPickerApp emojiPickerApp;*/
    app->hold();
    app->run();
    return 0;
}
