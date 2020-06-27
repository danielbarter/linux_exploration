#!/bin/bash

clang --static -o init init.c
cat files | cpio -o -H newc > archive
gzip archive
