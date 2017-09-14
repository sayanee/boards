# nRF52

> "hello world" on-board blinky LED examples of various dev boards. Firmware is flashed from a MAC OSX.

## Blinky

:star: [nRF52 dev board](https://www.nordicsemi.com/eng/Products/Bluetooth-low-energy/nRF52-DK) :star:

1. Download [GNU ARM Embedded Toolchain](https://launchpad.net/gcc-arm-embedded) and copy to `/usr/local`
1. Download [J-Link](https://www.segger.com/downloads/jlink)
1. Download SDK [nRF51_SDK_v6.x.x](http://developer.nordicsemi.com/nRF5_SDK/), uncompress it and `cd` inside
1. Edit file `nrf51822/Source/templates/gcc/Makefile.posix` in the SDK

  ```sh
  ...
  GNU_INSTALL_ROOT := /usr/local/{NAME_OF_SDK_FOLDER}
  ...
  ```
1. View the blinky code at `nrf51822/Board/pca10001/blinky_example/main.c`
1. Go to the blinky `gcc` directory with `cd nrf51822/Board/pca10001/blinky_example/gcc`
1. View the `Makefile`
1. Compile it with `make -f Makefile all`
1. Go to the newly created `_build` directory with `cd _build`
1. Notice the created files `blinky_gcc_xxaa.bin` and `blinky_gcc_xxaa.hex`
1. Connect the nRF52 board to your laptop via the USB cable
1. Flash the blinky firmware with `JLinkExe -device nrf52 -if swd -speed 4000`
1. Type the following to load the program with JLink:

  ```sh
  J-Link>? # read the help for commands r and g
  ...
  J-Link>connect
  ...
  J-Link>loadbin blinky_gcc_xxaa.bin 0
  ...
  J-Link>loadbin blinky_gcc_xxaa.hex 0x16000
  ...
  J-Link>r
  ...
  J-Link>g
  J-Link>exit
  ```
1. View the on-board blinky LEDs

  ![](img/nrf52.gif)

#### Reference

1. [Getting started with nRF51 development on Mac OS X](https://devzone.nordicsemi.com/blogs/22/getting-started-with-nrf51-development-on-mac-os-x)
1. [Flashing to nRF52](https://devzone.nordicsemi.com/question/65980/flashing-to-nrf52/)
