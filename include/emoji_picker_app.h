#ifndef EMOJI_PICKER_APP_H
#define EMOJI_PICKER_APP_H

#include "emoji_picker.h"

class EmojiPickerApp {
  public:
    EmojiPickerApp();
    ~EmojiPickerApp();

    void toggle_window();
    static void hotkey_handler(const char *keystring, void *user_data);

  private:
    void on_window_closed();
    EmojiPicker *picker;
};

#endif
