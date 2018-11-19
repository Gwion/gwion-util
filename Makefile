ifeq (,$(wildcard config.mk))
$(shell cp config.mk.orig config.mk)
endif
include config.mk

DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$(@F:.o=.Td)

src := $(wildcard src/*.c)
obj := $(src:.c=.o)

CFLAGS += -Iinclude -D_GNU_SOURCE

all: libgwion_util.a

libgwion_util.a: include/generated.h ${obj}
	@$(info linking $@)
	@ar rcs $@ $^

include/generated.h: scripts/generate_header.c
	$(info generating generated.h)
	@cc ${DFLAGS} scripts/generate_header.c -o generate_header
	@./generate_header > include/generated.h
	@rm generate_header

.c.o: $(DEPDIR)/%.d
	$(info compile $(<:.c=))
	@${CC} $(DEPFLAGS) ${CFLAGS} -c $< -o $(<:.c=.o)
	@mv -f $(DEPDIR)/$(@F:.o=.Td) $(DEPDIR)/$(@F:.o=.d) && touch $@

clean:
	$(info cleaning)
	@rm src/*.o *.a

include $(wildcard .d/*.d)
