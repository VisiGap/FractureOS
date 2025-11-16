CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -ffreestanding -nostdlib -I../lib/libfracture/include
LDFLAGS := -nostdlib -static

SUBDIRS := init shell

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
