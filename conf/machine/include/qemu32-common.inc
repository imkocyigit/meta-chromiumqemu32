#@TYPE: Machine
#
#@NAME: Generic x86
#@DESCRIPTION: Machine configuration for generic x86 (32-bit) PCs. Supports a moderately wide range of drivers that should boot and be usable on "typical" hardware.

DEFAULTTUNE ?= "core2-32"
require conf/machine/include/tune-core2.inc
require conf/machine/include/genericx86-common.inc

PREFERRED_PROVIDER_virtual/kernel ?= "linux-yocto"
PREFERRED_PROVIDER_virtual/xserver ?= "xserver-xorg"

XSERVER ?= "${XSERVER_X86_BASE} \
            ${XSERVER_X86_EXT} \
            ${XSERVER_X86_MODESETTING} \
           "

MACHINE_EXTRA_RRECOMMENDS += "kernel-modules linux-firmware"

MACHINE_FEATURES_remove = " usbgadget alsa wifi efi keyboard"


IMAGE_FSTYPES += "wic wic.bmap tar.bz2"
WKS_FILE ?= "genericx86.wks.in"
EFI_PROVIDER ??= "grub-efi"
do_image_wic[depends] += "gptfdisk-native:do_populate_sysroot"
do_image_wic[recrdeptask] += "do_bootimg"

