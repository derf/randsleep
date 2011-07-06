include config.mk

src/randsleep: src/randsleep.c
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $<

install: src/randsleep
	install -m 755 src/randsleep ${bin_dir}
	install -m 644 src/randsleep.1 ${man_dir}/man1

uninstall:
	rm -f src/randsleep

clean:
	rm -f src/randsleep

.PHONY: all install uninstall clean
