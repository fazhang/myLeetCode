mks := $(shell ls -d *  | grep -v bin | grep -v makefile | grep -v new.sh)
all:
	@for i in $(mks); do mdir=`basename $$i`; (cd $$mdir; make all); done;
clean: 
	@for i in $(mks); do mdir=`basename $$i`; (cd $$mdir; make clean); done;
