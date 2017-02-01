# Install Toolchain

1. [Install pre-requisites](https://github.com/pfalcon/esp-open-sdk#macos)

  ```sh
  $ brew tap homebrew/dupes
  $ brew install binutils coreutils automake wget gawk libtool help2man gperf gnu-sed --with-default-names grep
  $ export PATH="/usr/local/opt/gnu-sed/libexec/gnubin:$PATH" # or add to profile
  ```
- Create a virtual disk and build esp-open-sdk on it

  ```
  $ sudo hdiutil create ~/Desktop/case-sensitive.dmg -volname "case-sensitive" -size 10g -fs "Case-sensitive HFS+"
  $ sudo hdiutil mount ~/Desktop/case-sensitive.dmg
  ```
- Ensure `gperf` is version below `3.1`, E.g. `3.0.3`. If not uninstall with `brew uninstall gperf`.

  ```sh
  $ gperf --version

  GNU gperf 3.0.3
  Copyright (C) 1989-1998, 2000-2004, 2006-2007 Free Software Foundation, Inc.
  This is free software; see the source for copying conditions.  There is NO
  warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  Written by Douglas C. Schmidt and Bruno Haible.
  ```
- Download `esp-open-sdk` with submodules and build it

  ```sh
  $ cd /Volumes/case-sensitive
  $ git clone --recursive https://github.com/pfalcon/esp-open-sdk.git
  $ cd esp-open-sdk
  $ make # takes about 25 minutes
  ```
- Move `esp-open-sdk` folder to another permanent location E.g. `~/Workspace/lib`

  ```sh
  cp -r /Volumes/case-sensitive/esp-open-sdk ~/Workspace/lib/esp-open-sdk
  cp: /Volumes/case-sensitive/esp-open-sdk/crosstool-NG/.build/xtensa-lx106-elf/build/build-cc-gcc-final/xtensa-lx106-elf/libstdc++-v3/include/bits/stamp-bits: Too many levels of symbolic links
  ```
