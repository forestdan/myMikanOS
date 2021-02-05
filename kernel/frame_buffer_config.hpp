#pragma once

#include <stdint.h>

enum PixelFormat { kPixelRGBResv8BitPerColor, kPixelBGRResv8BitPerColor,};

struct FrameBufferConfig {
    uint8_t* frame_buffer;
    uint32_t pixels_per_scan_line;
    uint32_t horizontal_resolution;
    uint32_t vertical_resolution;
    enum PixelFormat pixel_format;
};

struct UEFIDate {
    uint16_t year;
    uint8_t mouth;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};