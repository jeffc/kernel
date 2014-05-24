;/**
; * @file entry.S
; * 
; * Entrypoint. Calls kernel_main()
; *
; * @author Jeff Cooper <jeff@thejeffcooper.com>
; * @date 2014-05-24
; */

.globl x86_entry
.extern kernel_main


.section .text

multiboot_header:
  .align 4

  .long 0x1BADB002  /* magic number */
  .long 0x00        /* flags */
  .long - (0x1BADB002 + 0x00)  /* checksum */


x86_entry:
  cli
  call kernel_main
  hlt

