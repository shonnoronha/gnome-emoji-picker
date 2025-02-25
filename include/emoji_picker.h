#ifndef EMOJI_PICKER_H
#define EMOJI_PICKER_H

#include <gtkmm.h>
#include <keybinder-3.0/keybinder.h>

class EmojiPicker : public Gtk::Window {

  public:
    EmojiPicker();
    virtual ~EmojiPicker();

  protected:
    bool on_delete_event(GdkEventAny *event) override;

  private:
    Gtk::Box m_main_box;
    Gtk::ScrolledWindow m_scrolled_window;
    Gtk::FlowBox m_flow_box;

    void load_emojis();
    void on_emoji_selected(Gtk::FlowBoxChild *child);
    static void hotkey_handler(const char *keystring, void *user_data);
    void toggle_window();
    void insert_to_active_window(const std::string &text);
};

#endif
