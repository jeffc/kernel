/**
 * @file link.ld
 *
 * Linker script
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-24
 */

OUTPUT_FORMAT(elf32-i386)
ENTRY(x86_entry)
SECTIONS
{
  . = 0x100000;
  .text : { *(.multiboot) *(.text) }
  .data : { *(.data) }
  .bss  : { *(.bss)  }
}
