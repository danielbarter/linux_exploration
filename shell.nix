with (import <nixpkgs> {});
mkShell {
  buildInputs = [ qemu
                  clang
                  glibc.static
                ];
}
