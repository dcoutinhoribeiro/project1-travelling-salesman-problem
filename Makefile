all: node.o path.o main.o 
	gcc node.o path.o main.o -o lista	-std=c99	-pedantic-errors	-Wall	-lm
	
node.o:	
	gcc -c ./path/node/node.c  -o node.o

path.o:	
	gcc	-c ./path/path.c  -o path.o 

main.o:	
	gcc -c	main.c 

clean:	
	rm	**.o	

run:
	./lista 

