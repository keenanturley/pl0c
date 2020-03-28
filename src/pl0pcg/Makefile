pl0pcg : parser.o symbol.o token_list.o token.o codegen.o error.o

parser.o : parser.c parser.h symbol.h codegen.h error.h
	gcc -c parser.c

symbol.o : symbol.c symbol.h
	gcc -c symbol.c

token_list.o : ../common/token_list.c ../common/token_list.h ../common/token.h
	cd ../common && $(MAKE)

token.o : ../common/token.c ../common/token.h
	cd ../common && $(MAKE)

codegen.o : codegen.c codegen.h error.h
	gcc -c codegen.c

error.o : error.c error.h
	gcc -c error.c

clean :
	rm -f *.o
