/**
 * @file asm.h
 *
 * Wrappers for assembly functions.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-29
 */

#ifndef _UTIL_ASM_H_
#define _UTIL_ASM_H_

#include <stdint.h>

/**
 * Read a byte from a port.
 *
 * @param[in] port The port.
 *
 * @return A byte.
 */
uint8_t inb(uint16_t port);

/**
 * Write a byte to a port.
 *
 * @param[in] port The port.
 * @param[in] value The byte to write.
 *
 * @return void.
 */
void outb(uint16_t port, uint8_t value);

#endif /* _UTIL_ASM_H_ */
