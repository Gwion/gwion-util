GWION_PACKAGE=gwion_util
CFLAGS += -DGWION_PACKAGE='"${GWION_PACKAGE}"'
MEM_UNSECURE ?=
POOL_CHECK ?=

ifeq (${MEM_UNSECURE}, 1)
CFLAGS += -DMEM_UNSECURE
endif

ifeq (${POOL_CHECK}, 1)
CFLAGS += -DPOOL_CHECK
endif

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
	$(info installing gwion_util in ${PREFIX})
	@install libgwion_util.a ${DESTDIR}/${PREFIX}
	@mkdir -p ${DESTDIR}/${PREFIX}/include/gwion/util
	@cp include/*.h ${DESTDIR}/${PREFIX}/include/gwion/util

uninstall: translation-uninstall
	$(info uninstalling lib${PACKAGE}.a from ${PREFIX})
	@rm -rf ${PREFIX}/${PREFIX}/lib${PACKAGE}.a
	@rm -rf ${PREFIX}/${PREFIX}/include/gwion/util

include $(wildcard .d/*.d)
include intl.mk
