compile2	:
	gcc 2.h
	gcc -c 2.c
	gcc -c driver2.c
	gcc 2.c driver2.c
	
compile3	:
	gcc linkedlist.h
	gcc -c linkedlist.c
	gcc 3.h
	gcc -c 3.c
	gcc 2.h
	gcc linkedlist.c 3.c 2.c
	
compile4	:
	gcc linkedlist.h
	gcc 2.h
	gcc 3.h
	gcc -c linkedlist.c
	gcc -c 2.c
	gcc -c 3.c
	gcc -c cycle1.c
	gcc -c cycle2.c
	gcc linkedlist.c 2.c 3.c cycle1.c cycle2.c -o out
	

compile5	:
	gcc linkedlist.h
	gcc 2.h
	gcc 3.h
	gcc 5.h
	gcc -c linkedlist.c
	gcc -c 2.c
	gcc -c 3.c
	gcc -c cycle1.c
	gcc -c cycle2.c
	gcc -c 5.c
	gcc linkedlist.c 2.c 3.c cycle1.c cycle2.c 5.c -o out1


compilell	:
	gcc 2.h
	gcc -c 2.c
	gcc linkedlist.h
	gcc -c linkedlist.c
	gcc -c driver.c
	gcc 2.c driver.c linkedlist.c
