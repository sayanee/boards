# Hello World Blinky

1. Go to `esp-open-sdk/examples/blinky`
- [Edit files](https://github.com/sayanee/esp-open-sdk/commit/ad2217c8457c19efb7410792ef41c21d437dc243) `blinky.c` and `Makefile`
- Download and install [driver for CH340](http://www.mblock.cc/posts/run-makeblock-ch340-ch341-on-mac-os-sierra) for nodeMCU
- Add to the PATH

  ```sh
  export PATH="/Users/username/Workspace/lib/esp-open-sdk/xtensa-lx106-elf/bin/:$PATH" # or add to profile
  ```
- Plug in nodeMCU with USB to the laptop
- Ensure `/dev/tty.wchusbserial*` exists. Replace the full path in `Makefile` line 14
- Run `make flash` to flash the code in the nodeMCU

  ```sh
  $ make flash

  esptool.py --port /dev/tty.wchusbserial1410 write_flash 0 blinky-0x00000.bin 0x10000 blinky-0x10000.bin
  esptool.py v1.2
  Connecting...
  Auto-detected Flash size: 32m
  Running Cesanta flasher stub...
  Flash params set to 0x0040
  Writing 36864 @ 0x0... 36864 (100 %)
  Wrote 36864 bytes at 0x0 in 3.2 seconds (91.6 kbit/s)...
  Writing 196608 @ 0x10000... 196608 (100 %)
  Wrote 196608 bytes at 0x10000 in 16.9 seconds (92.8 kbit/s)...
  Leaving...
  ```
- See the blinking LED on the nodeMCU board
- Copy the folder `examples/blinky` to another location and ensure that `make flash` is successful.

  ```c
  os_timer_arm(&some_timer, 2000, 1); // amend blinky interval to 2 seconds
  ```
