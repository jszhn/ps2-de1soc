/*
 * If we're working on CPUlator, we can concatenate into a single file with
 *      gcc -save-temps -CC -Wall -S demo/main.c
 * Make sure the definition below isn't commented out
 * Use main.i in CPUlator
 */
// #define CPULATOR

/*
 * If we're working with the Nios II soft core processor on the board
 * Comment this out if we're working with the ARM Cortex A9
 */
#define NIOS
#ifdef NIOS

#include "nios_asm.h"
#include "nios_control_register_macros.h"
#include "ps2_nios.h"

#endif

/*
 * Other standard includes
 */
#include "../ps2.h"
#include "de1soc_utilities.h"

int main (int argc, char **argv) {
    // board set-up
    ps2_clear_fifo();
    ps2_init_mouse();
    ps2_enable_interrupts();

    for (;;) {
        if (x_abs != x_previous || y_abs != y_previous) { // if new point
            vga_draw_pixel(x_previous, y_previous, 0x0); // clear previous point
            vga_draw_pixel(x_abs, y_abs, 0xFFFF); // draw new point
        }
    }
}

// see comment at top of file
#ifdef CPULATOR

#include "ps2.c"
#include "ps2_nios.c"

#endif