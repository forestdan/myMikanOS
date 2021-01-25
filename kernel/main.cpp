#include <cstdint>
#include <cstddef>
#include <cstdio>

#include "frame_buffer_config.hpp"
#include "graphics.hpp"
#include "font.hpp"
#include "console.hpp"

char pixel_writer_buf[sizeof(RGBVResv8BitPerColorPixelWriter)];
PixelWriter* pixel_writer;

void* operator new(size_t size, void* buf) {
    return buf;
}

void operator delete(void* obj) noexcept {

}

extern "C" void KernelMain(const FrameBufferConfig& frame_buffer_config) {
    /***********************************************************/
    switch(frame_buffer_config.pixel_format) {
        case kPixelRGBResv8BitPerColor:
            pixel_writer = new(pixel_writer_buf)
                RGBVResv8BitPerColorPixelWriter{frame_buffer_config};
            break;
        case kPixelBGRResv8BitPerColor:
            pixel_writer = new(pixel_writer_buf)
                BGRVResv8BitPerColorPixelWriter{frame_buffer_config};
            break;
    }
    for (int x = 0; x < frame_buffer_config.horizontal_resolution; x++) {
        for (int y = 0; y < frame_buffer_config.vertical_resolution; y++) {
            pixel_writer->Write(x, y, {255, 255, 255});
        }
    }
    // for (int x = 0; x < 200; x++) {
    //     for (int y = 0; y < 100; y++) {
    //         pixel_writer->Write(x, y, {0, 255, 0});
    //     }
    // }

    // WriteAscii(*pixel_writer, 50, 50, 'A', {0, 0, 0});
    // WriteAscii(*pixel_writer, 58, 50, 'A', {0, 0, 0});
    // int i = 0;
    // for (char c = '!'; c <= '~'; c++,i++) {
    //     WriteAscii(*pixel_writer, i * 8, 50, c, {0, 0, 0});
    // }
    // WriteString(*pixel_writer, 0, 66, "Hello World", {0, 0, 255});
    // char buf[128];
    // sprintf(buf, "1 + 2 = %d", 1 + 2);
    // WriteString(*pixel_writer, 0, 82, buf, {0, 0, 0});
    char buf[128];
    Console console = Console(*pixel_writer, {0, 0, 0}, {255, 255, 255});
    for (int i = 0; i < 27; i++) {
        sprintf(buf, "line%d\n", i);
        console.PutString(buf);
    }
    while(1) __asm__("hlt");
}