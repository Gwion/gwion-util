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

all: options-show include/generated.h libgwion_util.a

options-show:
	@$(call _options)

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

install: translation-install libgwion_util.a
	$(info installing $^ in ${PREFIX})
	@install lib${PACKAGE}.a ${PREFIX}

uninstall: translation-uninstall
	$(info uninstalling lib${PACKAGE}.a from ${PREFIX})
	@rm -rf ${PREFIX}/lib${PACKAGE}.a

include $(wildcard .d/*.d)
include target.mk
include intl.mk
