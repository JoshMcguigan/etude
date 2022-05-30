CC=gcc
CFLAGS = -g -Wall -fsanitize=address

build/krc/%: krc/%.c
	@mkdir -p build/krc
	$(CC) $(CFLAGS) -o $@ $<

LIB_SOURCES = $(wildcard adm/lib/*.c)
LIB_OBJECTS = $(patsubst adm/lib/%.c, build/adm/lib/%.o, $(LIB_SOURCES))
BINS = $(wildcard build/adm/*)

build/adm/%: adm/%.c $(LIB_OBJECTS)
	@mkdir -p build/adm
	$(CC) $(CFLAGS) -o $@ $< $(LIB_OBJECTS)

build/adm/lib/%.o: adm/lib/%.c
	@mkdir -p build/adm/lib
	$(CC) $(CFLAGS) -c -o $@ $<

.SECONDARY: $($(LIB_OBJECTS), $(BINS))

# This is a phony target, but make does not support
# wildcards in phony targets. In this case that is ok,
# since we will not ever have any actual filename
# that fits this pattern, so make will always assume
# it needs to rebuild this target anyway.
run-adm-%: build/adm/%
	./$<
