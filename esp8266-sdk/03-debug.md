# Debug

1. Power the nodeMCU with another power supply
- Connect the serial UART console cable to nodeMCU

  ```sh
  white wire to pin TX
  green wire to pin RX
  black wire to pin G
  red wire to none # nodeMCU is already powered
  ```
- Start `screen` with baud rate

  ```sh
  screen /dev/tty.usbserial 115200
  ```
- Quit screen with `Ctrl A + Ctrl /`

  ```
  Really quit and kill all your windows [y/n]
  ```
