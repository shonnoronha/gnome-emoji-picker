#include "emoji_picker_app.h"
#include <keybinder-3.0/keybinder.h>

EmojiPickerApp::EmojiPickerApp() : picker(nullptr) {
    keybinder_init();
    keybinder_bind("<Super>period", &EmojiPickerApp::hotkey_handler, this);
}

EmojiPickerApp::~EmojiPickerApp() {
    keybinder_unbind("<Super>period", &EmojiPickerApp::hotkey_handler);
}

void EmojiPickerApp::toggle_window() {
    if (picker && picker->is_visible()) {
        picker->hide();
    } else {
        if (!picker) {
            picker = new EmojiPicker();
            picker->signal_hide().connect(
                sigc::mem_fun(*this, &EmojiPickerApp::on_window_closed));
        }
        picker->show();
        picker->present();
    }
}

void EmojiPickerApp::hotkey_handler(const char *keystring, void *user_data) {
    auto *app = static_cast<EmojiPickerApp *>(user_data);
    app->toggle_window();
}

void EmojiPickerApp::on_window_closed() {
    delete picker;
    picker = nullptr;
}
