FROM debian:latest
WORKDIR /kosmos_os

RUN apt update -y > /dev/null && apt install git -y > /dev/null
RUN git clone --branch build_in_docker https://github.com/Osssy010101/kosmos.git

WORKDIR /kosmos_os/kosmos/
RUN chmod +x ./toolchain/build/install_on_debian.sh && chmod +x ./toolchain/build/install.sh
RUN ./toolchain/build/install_on_debian.sh 