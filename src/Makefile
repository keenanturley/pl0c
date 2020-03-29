compile: main.o
	gcc -o compile main.c common/token_list.o common/token.o pl0la/util.o \
	pl0la/scanner.o pl0pcg/parser.o pl0pcg/symbol.o pl0pcg/codegen.o \
	pl0pcg/error.o pm0vm/pm0.o pm0vm/loader.o pm0vm/debug.o	

.PHONY : pl0la pl0pcg pm0vm

main.o : pl0la pl0pcg pm0vm
	gcc -c main.c

pl0la : 
	$(MAKE) -C pl0la

pl0pcg :
	$(MAKE) -C pl0pcg

pm0vm :
	$(MAKE) -C pm0vm

clean :
	rm -f compile *.o && cd pm0vm && make clean && cd ../pl0la && make clean && \
	cd ../pl0la && make clean && cd ../pl0pcg && make clean && cd ../common && make clean
