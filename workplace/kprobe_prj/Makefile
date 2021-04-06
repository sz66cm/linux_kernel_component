PRJNAME:=cm_kprobe
obj-m =$(PRJNAME).o
$(PRJNAME)-objs := cmmodule.o kprobe.o
KVERSION = $(shell uname -r)
all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean

