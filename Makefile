include config.mk

src/randsleep: src/randsleep.c
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $<

install: src/randsleep

uninstall:
	rm -f src/randsleep

clean:
	rm -f src/randsleep

.PHONY: all install uninstall clean
