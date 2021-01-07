#! /bin/sh
MY_MIKANOS_DIR="/home/lab/myMikanos"
MY_MIKANOS_LOADER="/home/lab/edk2/Build/MikanLoaderX64/DEBUG_CLANG38/X64/Loader.efi"
KERNEL_LIST="$MY_MIKANOS_DIR/kernel/kernel.elf"

~/osbook/devenv/run_qemu.sh $MY_MIKANOS_LOADER $KERNEL_LIST