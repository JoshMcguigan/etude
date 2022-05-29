CC=gcc

build/krc/%: krc/%.c
	@mkdir -p build/krc
	$(CC) -fsanitize=address -g -o $@ $<

LIB_SOURCES = $(wildcard adm/lib/*.c)
LIB_OBJECTS = $(patsubst adm/lib/%.c, build/adm/lib/%.o, $(LIB_SOURCES))

build/adm/%: adm/%.c $(LIB_OBJECTS)
	@mkdir -p build/adm
	$(CC) -fsanitize=address -g -o $@ $< $(LIB_OBJECTS)

build/adm/lib/%.o: adm/lib/%.c
	@mkdir -p build/adm/lib
	$(CC) -g -c -o $@ $<

.SECONDARY: $(LIB_OBJECTS)
