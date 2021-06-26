FROM qmkfm/base_container
# FROM archlinux

ENV LANG=en_US.UTF-8

ADD entrypoint.sh /
VOLUME /qmk_firmware
WORKDIR /qmk_firmware

ENTRYPOINT /entrypoint.sh
