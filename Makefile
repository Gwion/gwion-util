include ../config.mk

DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$(@F:.o=.Td)

src := $(wildcard src/*.c)
obj := $(src:.c=.o)

CFLAGS += -I../include
libgwion_ast.a: ${obj}
	ar rcs $@ $^

parser:
	$(info generating parser)
	@${YACC} -o src/ast/parser.c --defines=include/parser.h utils/gwion.y

lexer:
	$(info generating lexer)
	@${LEX}  -o src/ast/lexer.c utils/gwion.l

.c.o: $(DEPDIR)/%.d
	$(info compile $(<:.c=))
	@${CC} $(DEPFLAGS) ${CFLAGS} -c $< -o $(<:.c=.o)
	@mv -f $(DEPDIR)/$(@F:.o=.Td) $(DEPDIR)/$(@F:.o=.d) && touch $@

clean:
	rm src/*.o

include $(wildcard .d/*.d)
