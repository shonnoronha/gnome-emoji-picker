#include "emoji_picker.h"
#include "emoji_loader.h"
#include "gtkmm/button.h"
#include "gtkmm/clipboard.h"
#include "gtkmm/enums.h"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <gdk/gdkx.h>
#include <keybinder-3.0/keybinder.h>
#include <nlohmann/json.hpp>

EmojiPicker::EmojiPicker() {
    set_title("Emoji Picker");
    set_default_size(400, 300);
    set_position(Gtk::WIN_POS_CENTER);
    set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG);
    set_keep_above();
    m_main_box.set_orientation(Gtk::ORIENTATION_VERTICAL);

    m_main_box.set_spacing(6);
    m_main_box.set_border_width(10);
    add(m_main_box);

    m_scrolled_window.set_propagate_natural_height(true);
    m_scrolled_window.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
    m_scrolled_window.set_min_content_height(200);

    m_flow_box.set_valign(Gtk::ALIGN_START);
    m_flow_box.set_max_children_per_line(10);
    m_flow_box.set_selection_mode(Gtk::SELECTION_SINGLE);
    m_flow_box.set_homogeneous(true);
    m_flow_box.set_row_spacing(6);
    m_flow_box.set_column_spacing(6);

    m_flow_box.signal_child_activated().connect(
        sigc::mem_fun(*this, &EmojiPicker::on_emoji_selected));

    load_emojis();

    m_scrolled_window.add(m_flow_box);
    m_main_box.pack_start(m_scrolled_window, true, true);
    show_all();
}

EmojiPicker::~EmojiPicker() {}

bool EmojiPicker::on_delete_event(GdkEventAny *event) {
    hide();
    return true;
}

void EmojiPicker::copy_emoji_to_clipboard(const std::string &text) {
    auto clipboard = Gtk::Clipboard::get();
    clipboard->set_text(text);
    hide();
}

void EmojiPicker::load_emojis() {
    std::vector<std::string> emojis =
        load_emojis_from_file(get_emoji_file_path());
    for (const auto &emoji : emojis) {
        auto button = Gtk::manage(new Gtk::Button(emoji));
        button->set_relief(Gtk::RELIEF_NONE);

        button->signal_clicked().connect([this, button]() {
            auto parent = button->get_parent();
            if (auto child = dynamic_cast<Gtk::FlowBoxChild *>(parent)) {
                m_flow_box.select_child(*child);
                on_emoji_selected(child);
            }
        });

        auto child = Gtk::manage(new Gtk::FlowBoxChild());
        child->add(*button);
        child->set_can_focus(true);
        m_flow_box.add(*child);
    }
}

void EmojiPicker::on_emoji_selected(Gtk::FlowBoxChild *child) {
    if (!child)
        return;

    auto button = dynamic_cast<Gtk::Button *>(child->get_child());
    if (!button)
        return;

    std::string emoji = button->get_label();

    copy_emoji_to_clipboard(emoji);

    button->grab_focus();
}
