#include "console.hpp"
#include "font.hpp"
#include <cstring>

Console::Console(PixelWriter& writer, const PixelColor& fg_color, 
    const PixelColor& bg_Color) : writer_{writer}, fg_color_{fg_color}, 
    bg_Color_{bg_Color}, buffer_{}, cursor_row_{0}, cursor_colunm_{0} {
}

void Console::PutString(const char*s) {
    while(*s) {
        if (*s == '\n') {
            NewLine();
        } else if (cursor_colunm_ < kColumns - 1) {
            WriteAscii(writer_, 8 * cursor_colunm_, 16 * cursor_row_, *s, fg_color_);
            buffer_[cursor_row_][cursor_colunm_] = *s;
            cursor_colunm_++;
        }
        s++;
    }
}

void Console::NewLine() {
    cursor_colunm_ = 0;
    if (cursor_row_ < kRows - 1) {
        cursor_row_++;
    } else {
        for (int y = 0; y < 16 * kRows; y++) {
            for (int x = 0; x < 8 * kColumns; x++) {
                writer_.Write(x, y, bg_Color_);
            }
        }
        for (int row = 0; row < kRows - 1; row++) {
            memcpy(buffer_[row], buffer_[row + 1], kColumns + 1);
            WriteString(writer_, 0, 16 * row, buffer_[row], fg_color_);
        }
        memset(buffer_[kRows - 1], 0, kColumns + 1);
    }
}