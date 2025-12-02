FROM docker.io/debian:stable

RUN apt update && apt install -y build-essential fish git wget

RUN mkdir ~/bin && \
    wget -O ~/bin/bazelisk https://github.com/bazelbuild/bazelisk/releases/download/v1.27.0/bazelisk-linux-amd64 && \
    chmod +x ~/bin/bazelisk

ENV PATH="$PATH:/root/bin"
