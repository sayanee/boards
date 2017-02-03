// Reference: https://github.com/yuloh/esp-hello-world
#include "ets_sys.h"
#include "driver/uart.h"

extern int ets_uart_printf(const char *fmt, ...);

void user_init(void) {
  uart_init(BIT_RATE_9600, BIT_RATE_9600);
  ets_uart_printf("\n\nHello World!\r\n");
}
