.PHONY: all kernel userspace boot clean run

all: kernel userspace boot

kernel:
	cd kernel && cargo build --release

userspace:
	$(MAKE) -C userspace

boot:
	nasm -f bin boot/boot.asm -o build/boot.bin

clean:
	cd kernel && cargo clean
	$(MAKE) -C userspace clean
	rm -rf build/

run: all
	qemu-system-x86_64 -drive format=raw,file=build/fractureos.img

iso: all
	./tools/create-iso.sh

.DEFAULT_GOAL := all
