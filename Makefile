# Makefile – makefile of our first driver
 
# if KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq (${KERNELRELEASE},)
    obj-m := t1.o
# Otherwise we were called directly from the command line.
# Invoke the kernel build system.
else
    #KERNEL_SOURCE := /usr/src/$(shell uname -r)/build
    KERNEL_SOURCE := /lib/modules/$(shell uname -r)/build
    PWD := $(shell pwd)
default:
	${MAKE} -C ${KERNEL_SOURCE} M=${PWD} modules
 
clean:
    ${MAKE} -C ${KERNEL_SOURCE} M=${PWD} clean
endif