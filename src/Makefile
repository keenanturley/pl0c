compile : pm0vm pl0la pl0pcg common main.o
	gcc -o compile main.c common/token_list.o common/token.o pl0la/util.o \
	pl0la/scanner.o pl0pcg/parser.o pl0pcg/symbol.o pl0pcg/codegen.o \
	pl0pcg/error.o pm0vm/pm0.o pm0vm/loader.o pm0vm/debug.o

main.o : common pm0vm pl0la pl0pcg main.c
	gcc -c main.c

common : 
	cd common && $(MAKE)

pm0vm : 
	cd pm0vm && $(MAKE)

pl0la : 
	cd pl0la && $(MAKE)

pl0pcg : 
	cd pl0pcg && $(MAKE)

clean :
	rm -f *.o && cd pm0vm && make clean && cd ../pl0la && make clean && cd ../pl0la && make clean && cd ../pl0pcg && make clean
