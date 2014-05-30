;/**
; * @file asm.S
; *
; * Wrappers for assembly functions.
; *
; * @author Jeff Cooper <jeff@thejeffcooper.com>
; * @date 2014-05-29
; */

.globl inb
.globl outb

inb:
  xorl %eax, %eax
  movw 4(%esp), %dx
  in %dx, %al
  ret

outb:
  movw 4(%esp), %dx
  movb 8(%esp), %al
  out %al, %dx
  ret
