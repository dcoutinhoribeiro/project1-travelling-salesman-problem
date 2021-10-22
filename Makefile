all: tsp.o distance_list.o distance_list_node.o route.o path.o path_node.o main.o 
	gcc distance_list_node.o distance_list.o tsp.o route.o path.o path_node.o main.o -o tsp_solve -std=c99	-pedantic-errors	-Wall	-lm
	
path_node.o:	
	gcc -c ./path/path_node/path_node.c  -o path_node.o

path.o:	
	gcc	-c ./path/path.c -o path.o 

route.o:	
	gcc	-c ./route/route.c -o route.o 

distance_list_node.o:	
	gcc -c ./tsp/distance_list/distance_list_node/distance_list_node.c  -o distance_list_node.o

distance_list.o:	
	gcc	-c ./tsp/distance_list/distance_list.c -o distance_list.o 

tsp.o:	
	gcc	-c ./tsp/tsp.c -o tsp.o 

main.o:	
	gcc -c	main.c 

clean:	
	rm	**.o	

run: 
	./tsp_solve  