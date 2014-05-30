/**
 * @file gdt_static.S
 *
 * A statically-defined GDT. Might be replaced by "real code" (tm) as necessary.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-30
 */



.section .data

GDT_START: ;// The global descriptor table, in all it's glory
  .long 0x00000000, 0x00000000 ;// null descriptor. apparently it's important.
  .long 0x0000FFFF, 0x00CF9C00 ;// GDT[1]: code segment descriptor
  .long 0x0000FFFF, 0x00CF9200 ;// GDT[2]: data segment descriptor
GDT_END:

GDT_pointer:
  .short GDT_END - GDT_START - 1
  .long GDT_START


.text

.global load_gdt
load_gdt:
  lgdt GDT_pointer
  ljmp $0x8, $finish_loading

finish_loading:
  mov $0x10, %ax
  mov %ax, %ds
  mov %ax, %es
  mov %ax, %fs
  mov %ax, %gs
  mov %ax, %ss

  ret
