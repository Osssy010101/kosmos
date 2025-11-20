FROM debian:latest
WORKDIR /kosmos_os

COPY ./src /kosmos_os/src
COPY ./toolchain /kosmos_os/toolchain
COPY ./iso /kosmos_os/iso
COPY ./Makefile /kosmos_os/Makefile

WORKDIR /kosmos_os/toolchain/build/
RUN chmod +x install_on_debian.sh
RUN ./install_on_debian.sh