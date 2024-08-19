// funix/drivers/screen.c

#include "screen.h"
#include "io.h"

#define VIDEO_MEMORY 0xb8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

static char *video_memory = (char *)VIDEO_MEMORY;
static int cursor_x = 0;
static int cursor_y = 0;

void init_screen() {
    // Ekranı temizle
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 2; i += 2) {
        video_memory[i] = ' ';
        video_memory[i + 1] = 0x07; // Beyaz metin, siyah arka plan
    }
    cursor_x = 0;
    cursor_y = 0;
    move_cursor(cursor_x, cursor_y);
}

void print_char(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        int offset = (cursor_y * SCREEN_WIDTH + cursor_x) * 2;
        video_memory[offset] = c;
        video_memory[offset + 1] = 0x07; // Beyaz metin, siyah arka plan
        cursor_x++;
    }
    if (cursor_x >= SCREEN_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }
    if (cursor_y >= SCREEN_HEIGHT) {
        // Ekranı kaydır
        for (int i = 0; i < SCREEN_WIDTH * (SCREEN_HEIGHT - 1) * 2; i++) {
            video_memory[i] = video_memory[i + SCREEN_WIDTH * 2];
        }
        for (int i = SCREEN_WIDTH * (SCREEN_HEIGHT - 1) * 2; i < SCREEN_WIDTH * SCREEN_HEIGHT * 2; i += 2) {
            video_memory[i] = ' ';
            video_memory[i + 1] = 0x07;
        }
        cursor_y = SCREEN_HEIGHT - 1;
    }
    move_cursor(cursor_x, cursor_y);
}

void move_cursor(int x, int y) {
    unsigned int position = y * SCREEN_WIDTH + x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, position & 0xFF);
    outb(0x3D4, 0x0E);
    outb(0x3D5, (position >> 8) & 0xFF);
}
