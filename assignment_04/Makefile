obj-m += keyboard_mod.o

PWD := $(CURDIR)
KDIR := /lib/modules/$(shell uname -r)/build
MODDEST := /lib/modules/$(shell uname -r)/extra
MODNAME := keyboard_mod.ko

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

install: all
	sudo mkdir -p $(MODDEST)
	sudo cp -v $(MODNAME) $(MODDEST)/
	sudo depmod

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	sudo rm -f $(MODDEST)/$(MODNAME)
	sudo depmod

