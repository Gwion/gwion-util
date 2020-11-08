ifeq (${USE_DOUBLE}, 1)
CFLAGS +=-DUSE_DOUBLE
endif

ifeq (${USE_DEBUG}, 1)
CFLAGS += -fsanitize=address -fno-omit-frame-pointer -Og
LDFLAGS += -fsanitize=address -fno-omit-frame-pointer -Og
else
CFLAGS += -DNDEBUG -fomit-frame-pointer -fno-stack-protector -fno-common -Ofast
LDFLAGS += -fomit-frame-pointer -fno-stack-protector -fno-common -Ofast
endif

ifeq (${USE_LTO}, 1)
CFLAGS += -flto
LDFLAGS += -flto
endif

ifeq (${USE_GETTEXT}, 1)
CFLAGS += -DUSE_GETTEXT
endif

ifeq (${USE_COVERAGE}, 1)
CFLAGS += -ftest-coverage -fprofile-arcs -O0 -g
LDFLAGS += --coverage
endif

ifeq (${BUILD_ON_WINDOWS}, 1)
CFLAGS += -DBUILD_ON_WINDOWS=1 -D_XOPEN_SOURCE=700 -Wl,--export-all-symbols -static
endif

ifeq ($(shell uname), Darwin)
AR = /usr/bin/libtool
AR_OPT = -static $^ -o $@
else
AR = ar
AR_OPT = rcs $@ $^
endif

PACKAGE_INFO ?= -DGWION_PACKAGE='"$GWION_PACKAGE"'

.c.o:
	$(info compile $(<:.c=))
	@${CC} $(DEPFLAGS) ${CFLAGS} ${PACKAGE_INFO} -c $< -o $(<:.c=.o)
	@mv -f $(DEPDIR)/$(@F:.o=.Td) $(DEPDIR)/$(@F:.o=.d) && touch $@
	@echo $@: config.mk >> $(DEPDIR)/$(@F:.o=.d)

DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$(@F:.o=.Td)

define _options
  $(info PACKAGE : ${GWION_PACKAGE})
  $(info CC      : ${CC})
  $(info CFLAGS  : ${CFLAGS})
  $(info LDFLAGS : ${LDFLAGS})
endef
