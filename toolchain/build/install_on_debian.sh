#!/bin/sh

apt update -y > /dev/null
apt install make nasm gcc xorriso qemu-system texinfo build-essential bison flex git-lfs sudo xz-utils -y > /dev/null

git lfs install
git lfs pull

echo 'export PATH=/opt/i386-elf:$PATH' >> ~/.bashrc

exec sh