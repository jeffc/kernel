CC=gcc
CFLAGS= -std=c99 -m32 -Wall -Werror -pedantic -g
ASM=as
ASMFLAGS= --32
LD=ld
LDFLAGS= -m elf_i386 -T linker/link.ld

kernel_name=kernel

ASM_SOURCES= $(shell find . -type f -name '*.S')
C_SOURCES= $(shell find . -type f -name '*.c')

OBJECTS= $(ASM_SOURCES:.S=.o)
OBJECTS+=$(C_SOURCES:.c=.o)

.PHONY: all clean run

all: $(kernel_name)

clean:
	rm $(OBJECTS)

run: $(kernel_name)
	qemu-system-i386 -kernel $(kernel_name)

debug: $(kernel_name)
	qemu-system-i386 -s -S -kernel $(kernel_name)


$(kernel_name) : $(OBJECTS)
	echo $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@  $(OBJECTS)

%.o : %.S
	$(ASM) $(ASMFLAGS)  $*.S -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $@

