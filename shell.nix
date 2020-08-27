with (import <nixpkgs> {});
mkShell {
  buildInputs = [ musl
                  qemu
                  clang
                ];
}
