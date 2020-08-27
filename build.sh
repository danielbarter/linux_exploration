musl-clang -v -static -o init init.c
cat files | cpio -o -H newc > archive
gzip -f archive
