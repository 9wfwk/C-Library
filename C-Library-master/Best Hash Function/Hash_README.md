##The module is for the code to detect the best Hash function
* The hash function takes a string, a baseNumber, and a tableSize variables as inputs and returns a number in range [0, tableSize ). 
* Hashing is be done as, Index = (((sum of ASCII values of characters in string) mod baseNumber) mod tableSize)
* A parser is implemented, taking input of a string and outputs vector of strings delimited by space
* Profiler, performs hasing for variable values of tableSize, ans baseNumber.
* The profiler then compares the hash function by the number of collisons occurring.
