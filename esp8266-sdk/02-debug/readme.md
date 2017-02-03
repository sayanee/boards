# Debug

1. Build the project

  ```sh
  make && make flash
  ```
- See the debug message `Hello World` every second with `screen`

  ```sh
  # ensure /dev/tty.wchusbserial1420 exists and check Makefile L28
  screen /dev/tty.wchusbserial1420 9600
  ```
