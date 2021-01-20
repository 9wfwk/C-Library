#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>
#include <math.h>

#ifndef ONE_H
#define ONE_H

#define WORDSIZE 100

struct String{
	char *arr;
	int len;
};

struct Dictionary{
	struct String *array; //string array.
	int size;
};

struct Collval{
	int ts;
	int bn;
	int best; //1 for least collison combination, 0 for all
};

typedef struct String string;
typedef struct Dictionary book;
typedef struct Pair pair;
typedef struct Collval profile;

string newString(int len);
/* returns a null string of capacity 100*/

book newBook(int size);
/* returns empty book variable*/

void printBook(book *bk);
/* prints the content of a book */

int hashFunction(string inp, int baseNumber, int tableSize);
/* returns a number in range [0,tableSize)
 * Hash (((sum of ASCII values of char in string)mod baseNumber)mod tableSize)
 */

int collisonCount(book bk, int baseNumber, int tableSize);
/* Calls hashFunction for all strings in strarr and return no. of times 
 * collison occurs for the given strarr and hashFunction
 */

book parsingFunction(char *filename);
/* reads filename and returns the array of strings(book)*/

profile* profiler(book *bk, int *ts);
/* Lesser number of coillisons
 * identify bestNumber and tableSize
 * Range - baseNumber 3 prime numbers [tableSize, 2*tableSize], 
 * 		      3 greater than 1000*tableSize
 *         tableSize - 5000, 50000, 500000
 *
 * Prints the collison values for aliceinwonderland, stopwords for 6*3 choices
 * Prints the best tableSize and baseNumbers indices.
 */
 
int isPrime(int num);

void printProfile(profile *pro);

#endif
