common : token_list.o token.o

token_list.o : token_list.c token_list.h token.h
	gcc -c token_list.c

token.o : token.c token.h
	gcc -c token.c
	
clean:
	rm -f *.o
