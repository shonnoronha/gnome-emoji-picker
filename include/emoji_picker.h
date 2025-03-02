#ifndef EMOJI_PICKER_H
#define EMOJI_PICKER_H

#include "emoji_loader.h"
#include "gtkmm/flowboxchild.h"
#include <gtkmm.h>
#include <keybinder-3.0/keybinder.h>
#include <vector>

class EmojiPicker : public Gtk::Window {

  public:
    EmojiPicker();
    virtual ~EmojiPicker();

  protected:
    bool on_delete_event(GdkEventAny *event) override;

  private:
    Gtk::Box m_main_box;
    Gtk::SearchEntry m_search_entry;
    Gtk::ScrolledWindow m_scrolled_window;
    Gtk::FlowBox m_flow_box;
    std::vector<EmojiData> m_emoji_data;
    std::string m_search_text;

    void load_emojis();
    void on_emoji_selected(Gtk::FlowBoxChild *child);
    static void hotkey_handler(const char *keystring, void *user_data);
    void copy_emoji_to_clipboard(const std::string &text);
    void on_search_changed();
    bool filter_emojis(Gtk::FlowBoxChild *child);
};

#endif
