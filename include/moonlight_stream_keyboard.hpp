/*
 * ps5-native-app-boilerplate - ProsperoLight component.
 * Copyright (C) 2026 BlackBearReloaded
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef MOONLIGHT_STREAM_KEYBOARD_HPP
#define MOONLIGHT_STREAM_KEYBOARD_HPP

#include <stddef.h>
#include <stdint.h>

enum class moonlight_keyboard_action : uint8_t
{
    key,
    shift,
    space,
    backspace,
    enter,
    close,
    ctrl,
    alt,
    win,
};

// Bit values match moonlight-common-c's MODIFIER_SHIFT/CTRL/ALT/META flags.
enum moonlight_keyboard_modifier : uint8_t
{
    moonlight_keyboard_modifier_shift = 0x01,
    moonlight_keyboard_modifier_ctrl = 0x02,
    moonlight_keyboard_modifier_alt = 0x04,
    moonlight_keyboard_modifier_win = 0x08,
};

// CTRL, ALT and WIN apply to the next key only; SHIFT stays until toggled off.
inline constexpr uint8_t moonlight_keyboard_one_shot_modifiers = moonlight_keyboard_modifier_ctrl |
                                                                 moonlight_keyboard_modifier_alt |
                                                                 moonlight_keyboard_modifier_win;

struct moonlight_keyboard_key
{
    const char *normal;
    const char *shifted;
    uint16_t virtual_key;
    moonlight_keyboard_action action;
};

inline constexpr moonlight_keyboard_key moonlight_keyboard_keys[] = {
    {"ESC", "ESC", 0x1b, moonlight_keyboard_action::key},
    {"F1", "F1", 0x70, moonlight_keyboard_action::key},
    {"F2", "F2", 0x71, moonlight_keyboard_action::key},
    {"F3", "F3", 0x72, moonlight_keyboard_action::key},
    {"F4", "F4", 0x73, moonlight_keyboard_action::key},
    {"F5", "F5", 0x74, moonlight_keyboard_action::key},
    {"F6", "F6", 0x75, moonlight_keyboard_action::key},
    {"F7", "F7", 0x76, moonlight_keyboard_action::key},
    {"F8", "F8", 0x77, moonlight_keyboard_action::key},
    {"F9", "F9", 0x78, moonlight_keyboard_action::key},
    {"F10", "F10", 0x79, moonlight_keyboard_action::key},
    {"F11", "F11", 0x7a, moonlight_keyboard_action::key},
    {"F12", "F12", 0x7b, moonlight_keyboard_action::key},

    {"1", "!", 0x31, moonlight_keyboard_action::key},
    {"2", "@", 0x32, moonlight_keyboard_action::key},
    {"3", "#", 0x33, moonlight_keyboard_action::key},
    {"4", "$", 0x34, moonlight_keyboard_action::key},
    {"5", "%", 0x35, moonlight_keyboard_action::key},
    {"6", "^", 0x36, moonlight_keyboard_action::key},
    {"7", "&", 0x37, moonlight_keyboard_action::key},
    {"8", "*", 0x38, moonlight_keyboard_action::key},
    {"9", "(", 0x39, moonlight_keyboard_action::key},
    {"0", ")", 0x30, moonlight_keyboard_action::key},
    {"-", "_", 0xbd, moonlight_keyboard_action::key},
    {"=", "+", 0xbb, moonlight_keyboard_action::key},
    {"`", "~", 0xc0, moonlight_keyboard_action::key},

    {"q", "Q", 0x51, moonlight_keyboard_action::key},
    {"w", "W", 0x57, moonlight_keyboard_action::key},
    {"e", "E", 0x45, moonlight_keyboard_action::key},
    {"r", "R", 0x52, moonlight_keyboard_action::key},
    {"t", "T", 0x54, moonlight_keyboard_action::key},
    {"y", "Y", 0x59, moonlight_keyboard_action::key},
    {"u", "U", 0x55, moonlight_keyboard_action::key},
    {"i", "I", 0x49, moonlight_keyboard_action::key},
    {"o", "O", 0x4f, moonlight_keyboard_action::key},
    {"p", "P", 0x50, moonlight_keyboard_action::key},
    {"[", "{", 0xdb, moonlight_keyboard_action::key},
    {"]", "}", 0xdd, moonlight_keyboard_action::key},
    {"\\", "|", 0xdc, moonlight_keyboard_action::key},

    {"a", "A", 0x41, moonlight_keyboard_action::key},
    {"s", "S", 0x53, moonlight_keyboard_action::key},
    {"d", "D", 0x44, moonlight_keyboard_action::key},
    {"f", "F", 0x46, moonlight_keyboard_action::key},
    {"g", "G", 0x47, moonlight_keyboard_action::key},
    {"h", "H", 0x48, moonlight_keyboard_action::key},
    {"j", "J", 0x4a, moonlight_keyboard_action::key},
    {"k", "K", 0x4b, moonlight_keyboard_action::key},
    {"l", "L", 0x4c, moonlight_keyboard_action::key},
    {";", ":", 0xba, moonlight_keyboard_action::key},
    {"'", "\"", 0xde, moonlight_keyboard_action::key},

    {"z", "Z", 0x5a, moonlight_keyboard_action::key},
    {"x", "X", 0x58, moonlight_keyboard_action::key},
    {"c", "C", 0x43, moonlight_keyboard_action::key},
    {"v", "V", 0x56, moonlight_keyboard_action::key},
    {"b", "B", 0x42, moonlight_keyboard_action::key},
    {"n", "N", 0x4e, moonlight_keyboard_action::key},
    {"m", "M", 0x4d, moonlight_keyboard_action::key},
    {",", "<", 0xbc, moonlight_keyboard_action::key},
    {".", ">", 0xbe, moonlight_keyboard_action::key},
    {"/", "?", 0xbf, moonlight_keyboard_action::key},

    {"SHIFT", "SHIFT", 0, moonlight_keyboard_action::shift},
    {"CTRL", "CTRL", 0xa2, moonlight_keyboard_action::ctrl},
    {"ALT", "ALT", 0xa4, moonlight_keyboard_action::alt},
    {"WIN", "WIN", 0x5b, moonlight_keyboard_action::win},
    {"TAB", "TAB", 0x09, moonlight_keyboard_action::key},
    {"SPACE", "SPACE", 0x20, moonlight_keyboard_action::space},
    {"DEL", "DEL", 0x2e, moonlight_keyboard_action::key},
    {"BACK", "BACK", 0x08, moonlight_keyboard_action::backspace},
    {"ENTER", "ENTER", 0x0d, moonlight_keyboard_action::enter},
    {"CLOSE", "CLOSE", 0, moonlight_keyboard_action::close},
};

inline constexpr uint8_t moonlight_keyboard_row_offsets[] = {0, 13, 26, 39, 50, 60, 70};
inline constexpr uint32_t moonlight_keyboard_key_count = 70;
inline constexpr uint32_t moonlight_keyboard_row_count = 6;

static_assert(sizeof(moonlight_keyboard_keys) / sizeof(moonlight_keyboard_keys[0]) ==
                  moonlight_keyboard_key_count,
              "keyboard layout and key count must agree");

inline uint32_t moonlight_keyboard_row(uint32_t selected)
{
    for (uint32_t row = 0; row < moonlight_keyboard_row_count; ++row)
        if (selected < moonlight_keyboard_row_offsets[row + 1])
            return row;
    return moonlight_keyboard_row_count - 1;
}

inline uint32_t moonlight_keyboard_move(uint32_t selected, int horizontal, int vertical)
{
    uint32_t row = moonlight_keyboard_row(selected);
    uint32_t start = moonlight_keyboard_row_offsets[row];
    uint32_t count = moonlight_keyboard_row_offsets[row + 1] - start;
    uint32_t column = selected - start;

    if (horizontal)
        column = (column + count + horizontal) % count;
    if (vertical)
    {
        row = (row + moonlight_keyboard_row_count + vertical) % moonlight_keyboard_row_count;
        start = moonlight_keyboard_row_offsets[row];
        count = moonlight_keyboard_row_offsets[row + 1] - start;
        if (column >= count)
            column = count - 1;
    }
    return moonlight_keyboard_row_offsets[row] + column;
}

inline const char *moonlight_keyboard_label(uint32_t selected, bool shifted)
{
    if (selected >= moonlight_keyboard_key_count)
        selected = 0;
    return shifted ? moonlight_keyboard_keys[selected].shifted
                   : moonlight_keyboard_keys[selected].normal;
}

inline uint8_t moonlight_keyboard_modifier_for(moonlight_keyboard_action action)
{
    switch (action)
    {
    case moonlight_keyboard_action::shift:
        return moonlight_keyboard_modifier_shift;
    case moonlight_keyboard_action::ctrl:
        return moonlight_keyboard_modifier_ctrl;
    case moonlight_keyboard_action::alt:
        return moonlight_keyboard_modifier_alt;
    case moonlight_keyboard_action::win:
        return moonlight_keyboard_modifier_win;
    default:
        return 0;
    }
}

struct moonlight_keyboard_event
{
    uint16_t virtual_key;
    bool down;
    // Modifiers held once this event is applied, as a physical keyboard reports them.
    uint8_t modifiers;
};

// Longest sequence: three modifier downs, key down, key up, three modifier ups.
inline constexpr uint32_t moonlight_keyboard_max_events = 8;

// CTRL, ALT and WIN are sent as real key presses around the key, since many
// Windows shortcuts only see the key state. SHIFT travels in the modifier flags.
inline uint32_t moonlight_keyboard_build_events(uint16_t virtual_key, uint8_t modifiers,
                                                moonlight_keyboard_event *out)
{
    static constexpr struct
    {
        uint8_t modifier;
        uint16_t virtual_key;
    } held[] = {
        {moonlight_keyboard_modifier_ctrl, 0xa2},
        {moonlight_keyboard_modifier_alt, 0xa4},
        {moonlight_keyboard_modifier_win, 0x5b},
    };
    uint32_t count = 0;
    uint8_t active = modifiers & moonlight_keyboard_modifier_shift;

    for (const auto &modifier : held)
        if (modifiers & modifier.modifier)
        {
            active |= modifier.modifier;
            out[count++] = {modifier.virtual_key, true, active};
        }
    out[count++] = {virtual_key, true, active};
    out[count++] = {virtual_key, false, active};
    for (int index = (int)(sizeof(held) / sizeof(held[0])) - 1; index >= 0; --index)
        if (modifiers & held[index].modifier)
        {
            active &= (uint8_t)~held[index].modifier;
            out[count++] = {held[index].virtual_key, false, active};
        }
    return count;
}

#endif
