Miscellaneous scripts for LF/FlexPRET.

Toolchain
=========
Make sure you have `spike` and `riscv64-unknown-elf-gcc` on your PATH.

You can get the toolchains below:

https://static.dev.sifive.com/dev-tools/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14.tar.gz
https://github.com/edwardcwang/riscv-toolchains/releases/download/toolchains/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14.tar.gz

https://www.sifive.com/boards


Bare-metal LF with GDB Workflow
=================
1. Write the LF program
2. Generate C code using `lfc -n <prog>.lf`
3. Swap out `<lf_prog_dir>/src-gen/core` with `lib/core_gdb`
4. Also copy `lib/start.S` into `src-gen`
5. Compile `src-gen/<prog>.c` using `scripts/compile.sh`
6. Start 3 different screen/tmux windows
7. In window 1, `cd <lf_prog_dir>/src-gen` and use `spike.sh` to launch the RISC-V binary `<prog_bin>`
8. In window 2, `cd gdb/` and do `openocd -f spike.cfg`
9. In window 3 (and subsequent actions will happen in this window), `cd <lf_prog_dir>/src-gen` and use `riscv32-unknown-elf-gdb <prog_bin>`
10. After `gdb` prompt shows up, type in `target remote localhost:3333`
11. Then, change the source dir to the project directory in `gdb` using `dir <lf_prog_dir>` (e.g. `$(gdb) dir ../../timer`). This is used to prevent certain "file not found" errors in `gdb`
12. There will be a spin wait at the beginning. Disable it to continue program execution by doing `print wait = 0`
13. Now feel free to use all of your favorite `gdb` commands to debug the program!
