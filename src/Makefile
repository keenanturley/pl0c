compile: common pm0vm pl0la pl0pcg
	cd common && $(MAKE)
	cd pm0vm && $(MAKE)
	cd pl0la && $(MAKE)
	cd pl0pcg && $(MAKE)
	gcc -c main.c
	gcc -o compile main.c common/token_list.o common/token.o pl0la/util.o \
	pl0la/scanner.o pl0pcg/parser.o pl0pcg/symbol.o pl0pcg/codegen.o \
	pl0pcg/error.o pm0vm/pm0.o pm0vm/loader.o pm0vm/debug.o	

clean :
	rm -f compile *.o && cd pm0vm && make clean && cd ../pl0la && make clean && \
	cd ../pl0la && make clean && cd ../pl0pcg && make clean && cd ../common && make clean
