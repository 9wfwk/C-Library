compRecMS: 
	gcc ex1.h
	gcc ex2.h
	gcc -c merge.c
	gcc -c recursiveSort.c
	gcc -c timeandspace_recursive.c
	gcc -c main_recursive_1024.c
	gcc main_recursive_1024.c merge.c recursiveSort.c timeandspace_recursive.c -o outRec1024
	gcc -c main_recursive_10240.c
	gcc main_recursive_10240.c merge.c recursiveSort.c timeandspace_recursive.c -o outRec10240

compIterMS:
	gcc ex1.h
	gcc ex2.h
	gcc -c merge.c
	gcc -c iterativeSort.c
	gcc -c timeandspace_iterative.c
	gcc -c main_iterative_1024.c
	gcc main_iterative_1024.c merge.c iterativeSort.c timeandspace_iterative.c -o outIter1024
	gcc -c main_iterative_10240.c
	gcc main_iterative_10240.c merge.c iterativeSort.c timeandspace_iterative.c -o outIter10240

	
runRecMS:
	./outRec1024
	./outRec10240
	
runIterMS:
	./outIter1024
	./outIter10240
	
compare:
	make runRecMS
	make runIterMS
