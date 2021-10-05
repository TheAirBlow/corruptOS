#include <memory/heap.h>
#include <video/gop.h>
#include <hardware/IO.h>
#include <debug/panic.h>
#include <hardware/pci.h>
#include <video/cstr.h>
#include <stdbool.h>

typedef struct {
    Framebuffer* framebuffer;
    PSF1_FONT* font;
    uint64_t kernelSize;
    void* kernelStart;
    void* kernelEnd;
} KernelData;

void _start(KernelData kernelData) {
    gopinit(kernelData.framebuffer, kernelData.font);
    print(0xFFFFFF, "Welcome to kernel b1.0!\n");
    print(0xFFFFFF, "Framebuffer End: ");
    print(0xFFFFFF, to_string64(kernelData.framebuffer->BaseAddress + kernelData.framebuffer->BufferSize));
    newline();
    print(0xFFFFFF, "Kernel End: ");
    print(0xFFFFFF, to_string64(kernelData.kernelEnd));
    newline();
    //mm_init(kernelData.kernelEnd);
    //pci_init();
    while(1);
}
