pl0pcg : parser.o symbol.o token_list.o token.o codegen.o error.o

parser.o : parser.c parser.h symbol.h codegen.h error.h
	gcc -c parser.c

symbol.o : symbol.c symbol.h
	gcc -c symbol.c

token_list.o : token_list.c token_list.h token.h
	gcc -c token_list.c

token.o : token.c token.h
	gcc -c token.c

codegen.o : codegen.c codegen.h error.h
	gcc -c codegen.c

error.o : error.c error.h
	gcc -c error.c

clean :
	rm -f *.o
