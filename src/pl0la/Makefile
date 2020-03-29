pl0la : util.o token_list.o token.o scanner.o

util.o : util.c util.h token_list.o
	gcc -c util.c

token_list.o : ../common/token_list.c ../common/token_list.h ../common/token.h
	$(MAKE) -C ../common

token.o : ../common/token.c ../common/token.h
	$(MAKE) -C ../common

scanner.o : scanner.c scanner.h token.o token_list.o
	gcc -c scanner.c

clean:
	rm -f *.o
