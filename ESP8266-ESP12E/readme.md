# ESP8266 ESP12E Module

> Using ESP12E module

- Hardware: ESP12E
- Firmware: Arduino

## Wiring

There are 2 types of modes: (1) Normal (2) Flashing

### (1) Normal mode

- ESP8266
    - `VCC` pin to `3.3V`
    - `EN` pin to `3.3V`
    - `GND` pin to `GND`
    - `GPIO15`	to `GND` with a resistor
    - `GPIO2` to `3.3V` with a resistor
- Battery
    - `5V` to `5V` rail
    - `GND` to `GND` rail

#### See the serial monitor

- Take out the battery
- Plug in the FTDI chip
- Watch the serial monitor on the Arduino IDE with `boot mode:(3,x)`

    ```sh
     ets Jan  8 2013,rst cause:2, boot mode:(3,6)
    ```

### (2) Flashing mode

> To enable ESP8266 firmware flashing GPIO0 pin must be pulled low before the device is reset. Conversely, for a normal boot, GPIO0 must be pulled high or floating. [[Ref](https://nodemcu.readthedocs.io/en/master/en/flash/#putting-device-into-flash-mode)]

- Battery
    - not connected!
- FTDI chip
    - `GND` to `GND`
    - `TX` pin to `RX` of ESP8266
    - `RX` pin to `TX` of ESP8266
    - `5V` pin to `VCC` of ESP8266
- ESP8266, ESP-12 module
    - `RX` pin to `TX` of FTDI chip
    - `TX` pin to `RX` of FTDI chip
    - `5V` pin to `VCC` of FTDI chip

#### See the serial monitor

- Plug in `GPIO0` of ESP8266 to `GND`
- Plug in the FTDI chip
- Watch the serial monitor on the Arduino IDE with `boot mode:(1,x)`
    ```sh
     ets Jan  8 2013,rst cause:2, boot mode:(1,1)
    ```
- Flash the firmware
