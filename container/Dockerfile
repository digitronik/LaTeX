FROM fedora:30
MAINTAINER Nikhil Dhandre (digitronik)

RUN dnf -y update && \
dnf -y install texlive-scheme-full && \
dnf clean all

WORKDIR /data
VOLUME ["/data"]
