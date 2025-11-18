#!/bin/sh

apt install make nasm gcc xorriso qemu-system texinfo build-essential bison flex git-lfs sudo -y > /dev/null

git lfs install
git lfs pull

if [ "$(id -u)" -ne 0 ]; then
    sh ./install.sh
else
    sudo sh ./install.sh
fi

export PATH=$PATH:/opt/i386-elf
export PATH=$PATH:/opt/i386-elf/i386-elf/bin