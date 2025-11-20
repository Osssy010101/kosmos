FROM debian:latest
WORKDIR /kosmos_os

COPY ./src /kosmos_os/src
COPY ./toolchain /kosmos_os/toolchain
COPY ./iso /kosmos_os/iso
COPY ./Makefile /kosmos_os/Makefile

WORKDIR /kosmos_os/toolchain/build
RUN chmod +x install_on_debian.sh
RUN ./install_on_debian.sh

WORKDIR /kosmos_os/toolchain/dists
RUN mkdir -p /opt/i386-elf
RUN tar xJf ./i386-elf-7.5.0-Linux-x86_64.tar.xz --strip-components=1 -C /opt/i386-elf