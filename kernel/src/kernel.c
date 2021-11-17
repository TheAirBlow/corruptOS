/**
 * @file kernel.c
 * @author TheAirBlow <theairblow-help@gmail.com>
 * @brief Main kernel file
 * 
 * @copyright Copyright TheAirBlow (c) 2021
 */
#include "kernel.h"

/**
 * @brief Get a Stivale2 tag structure
 * 
 * @param stivale2_struct Stivale structure
 * @param id ID
 * @return Stivale tag structure
 */
void* stivale2_get_tag(struct stivale2_struct *stivale2_struct, uint64_t id) {
    struct stivale2_tag *current_tag = (void *)stivale2_struct->tags;
    for (;;) {
        if (current_tag == NULL) return NULL;
        if (current_tag->identifier == id) return current_tag;
        current_tag = (void *)current_tag->next;
    }
}

/**
 * @brief Entrypoint
 */
void _start(struct stivale2_struct* stivale2) {
    struct stivale2_struct_tag_framebuffer* framebuffer = stivale2_get_tag(stivale2, STIVALE2_STRUCT_TAG_FRAMEBUFFER_ID);
    struct stivale2_struct_tag_terminal *terminal = stivale2_get_tag(stivale2, STIVALE2_STRUCT_TAG_TERMINAL_ID);
    void *term_write_ptr = (void *)terminal->term_write;
    void (*term_write)(const char *string, size_t length) = term_write_ptr;
    gop_init(framebuffer);
    term_write("Hello world!", 11);
    while(1);
}