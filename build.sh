#!/bin/sh

mkdir -p .build/                                      && \
    docker pull qmkfm/base_container                  && \
    docker build                                         \
       --iidfile .build/docker-build.id                  \
       docker_build/                                  && \
    docker run                                           \
       --rm -it                                          \
       -v $(pwd):/qmk_firmware                           \
       -w /qmk_firmware                                  \
       --privileged                                      \
       -v /dev:/dev                                      \
       $(<.build/docker-build.id)
