#ifndef DEBUG_BUFFERED_HW_UART_H
#define DEBUG_BUFFERED_HW_UART_H

#ifndef DEBUG_BUFFER_SIZE
#define DEBUG_BUFFER_SIZE (128)
#endif /* DEBUG_BUFFER_SIZE */

void su_send(unsigned char data);

void _debug_buffer_send_next_char(void);

/* void buffered_hw_debug_send_string(const char *str); */

#endif /* DEBUG_BUFFERED_HW_UART_H */
