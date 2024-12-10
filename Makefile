GWION_PACKAGE=gwion_util

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

SRC := $(wildcard src/*.c)

ifeq (${BUILD_ON_WINDOWS}, 1)
SRC += $(wildcard windows_missing/*.c)
CFLAGS += -Iwindows_missing
endif

OBJ := $(SRC:src/%.c=build/%.o)

CFLAGS += -D_GNU_SOURCE

all: options-show static

options-show:
	@$(call _options)

.PHONY: static
static: libgwion_util.a
libgwion_util.a: ${OBJ}
	echo ${OBJ}
	@$(info linking $@)
	@${AR} ${AR_OPT}

libtermcolor.a: build/termcolor.o
	@$(info linking $@)
	@${AR} ${AR_OPT}

libcmdapp.a: build/cmdapp.o
	@$(info linking $@)
	@${AR} ${AR_OPT}

clean:
	$(info cleaning)
	@rm -f ${OBJ} *.a

install: translation-install libgwion_util.a
	$(info installing ${GWION_PACKAGE} in ${PREFIX})
	@install libgwion_util.a ${DESTDIR}/${PREFIX}
	@mkdir -p ${DESTDIR}/${PREFIX}/include/gwion/util
	@cp include/*.h ${DESTDIR}/${PREFIX}/include/gwion/util

uninstall: translation-uninstall
	$(info uninstalling ${GWION_PACKAGE} from ${PREFIX})
	@rm -rf ${PREFIX}/${PREFIX}/lib${PACKAGE}.a
	@rm -rf ${PREFIX}/${PREFIX}/include/gwion/util

include $(wildcard .d/*.d)
include locale.mk
