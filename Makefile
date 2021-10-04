all:
	make -C ./bootloader/gnu-efi
	make -C ./bootloader
	make -C ./kernel
	make -C ./kernel buildimg

runall:
	make -C ./bootloader/gnu-efi
	make -C ./bootloader
	make -C ./kernel
	make -C ./kernel buildimg
	make -C ./kernel run

bootloader:
	make -C ./bootloader/gnu-efi
	make -C ./bootloader

kernel: make -C ./kernel
buildimg: make -C ./kernel buildimg
run: make -C ./kernel run
