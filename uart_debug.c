#include "uart_debug.h"

void su_send_byte(unsigned char by) {
  su_send('0' + by / 100);
  su_send('0' + (by / 10) % 10);
  su_send('0' + by % 10);
}

void su_send_byte_hex(unsigned char by) {
  if ((by >> 4) > 9) {
    su_send('a' + (by >> 4) - 10);
  } else {
    su_send('0' + (by >> 4));
  }

  if ((by & 0x0f) > 9) {
    su_send('a' + (by & 0x0f) - 10);
  } else {
    su_send('0' + (by & 0x0f));
  }
}


void su_send_string(const char *str) {
  while (*str) {
    su_send(*str);
    str++;
  }
}


