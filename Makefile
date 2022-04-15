CC=gcc

build/krc/%: krc/%.c
	@mkdir -p build/krc
	$(CC) -o $@ $<
