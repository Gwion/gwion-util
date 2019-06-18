PACKAGE=gwion_util
CFLAGS += -DPACKAGE='"${PACKAGE}"'

ifeq (,$(wildcard config.mk))
$(shell cp config.mk.orig config.mk)
endif
include config.mk

src := $(wildcard src/*.c)

ifeq (${BUILD_ON_WINDOWS}, 1)
src += $(wildcard windows_missing/*.c)
CFLAGS += -Iwindows_missing -DBUILD_ON_WINDOWS -D_XOPEN_SOURCE=700
endif
obj := $(src:.c=.o)

CFLAGS += -D_GNU_SOURCE

all: options include/generated.h libgwion_util.a

libgwion_util.a: ${obj}
	@$(info linking $@)
	@${AR} ${AR_OPT}

include/generated.h: scripts/generate_header.c
	$(info generating generated.h)
	@${CC} ${CFLAGS} ${DFLAGS} scripts/generate_header.c -o generate_header
	@./generate_header > include/generated.h
	@rm generate_header

clean:
	$(info cleaning)
	@rm -f ${obj} *.a

install: libgwion_util.a
	$(info installing in ${PREFIX})
	$(info installing $^)
	@install $^ ${PREFIX}/lib

include $(wildcard .d/*.d)
include target.mk
include intl.mk
