#!/bin/bash

rep_name='kosmos'

apt install make nasm gcc xorriso qemu-system texinfo build-essential bison flex git-lfs -y

cd $rep_name

git lfs install
git lfs pull

sudo ./install.sh

export PATH=$PATH:/opt/i386-elf
export PATH=$PATH:/opt/i386-elf/i386-elf/bin
# Перезапуск сесси
exec bash

cd ../../

make