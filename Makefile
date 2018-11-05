NAME=timedrel
VERSION=0.3

BASEDIR?=$(shell pwd)
PREFIX?=/usr/local

all: install

install:
	cp -R ./include/timedrel/ $(PREFIX)/include/

uninstall:
	rm -rf $(PREFIX)/include/timedrel

develop:
	mkdir $(PREFIX)/include/timedrel
	ln -s $(BASEDIR)/include/timedrel/* $(PREFIX)/include/timedrel

test:


.PHONY: test develop install uninstall all