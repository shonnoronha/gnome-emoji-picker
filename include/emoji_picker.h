#ifndef EMOJI_PICKER_H
#define EMOJI_PICKER_H

#include <gtkmm.h>

class EmojiPicker : public Gtk::Window {
  public:
    EmojiPicker();

  protected:
    void load_emojis();
    void on_emoji_selected(Gtk::FlowBoxChild *child);

  private:
    Gtk::Box m_main_box;
    Gtk::ScrolledWindow m_scrolled_window;
    Gtk::FlowBox m_flow_box;
};

#endif 
