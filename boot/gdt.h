/**
 * @file gdt.h
 *
 * Definitions for dealing with the GDT.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-30
 */

#ifndef _BOOT_GDT_H_
#define _BOOT_GDT_H_

/**
 * Load the GDT.
 *
 * @return void.
 */
void load_gdt();

#endif /* _BOOT_GDT_H_ */
