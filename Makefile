CFLAGS=$(shell cat compile_flags.txt)
OFLAGS=-O3

hexxer: hexxer.cpp
	$(CXX) $(CFLAGS) $(OFLAGS) $< -o $@

install: hexxer
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f hexxer ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/hexxer
