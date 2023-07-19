# Intro to Programming: ECS36A Fall 2020

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

## Homework 1
### min_coins.c:
This program is designed to calculate the minimum number of coins needed to make up a certain amount of cents. It takes a number of cents as an input from the user and returns the number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent) required to make up the given amount. The program uses division and modulus operations to calculate the number of each coin type needed, always prioritizing the highest denomination first.

### sum_prod.c:
This program takes two integer inputs from the user and calculates both their sum and product. After prompting the user to enter two numbers, it adds and multiplies these numbers respectively, then outputs the results. The program is an elementary example of basic arithmetic operations in C, showcasing the use of addition and multiplication operators on user input.

## Homework 2
### prog2.c:
This C program consists of a number of functions that perform various character and numerical operations.

- The functions isUpper(), isLower(), isAlpha(), and isDigit() take an integer as an argument, representing a character in ASCII, and return 1 if the character is an uppercase letter, a lowercase letter, an alphabet letter, or a digit respectively. Otherwise, they return 0.

- **toLower()/toUpper()**: The functions take an integer argument and return its lowercased or uppercased version respectively.

- **foo()**: The function prompts the user to enter characters until a non-lowercase letter is entered. It returns the number of characters entered before the non-lowercase character. If the non-lowercase character is an uppercase letter, it prints a specific message.

- **goo()**: The function prompts the user to enter pairs of integers (num1 and num2) and calculates the cumulative sum of their products until the product of a pair is 0. It returns the total sum.

- **foo2()**: The function takes two integers, n and k, as input and returns the count of numbers from 1 to n that have exactly k divisors.

The main() function at the end of the program calls foo2() with two different sets of arguments and prints out the returned results. This code demonstrates basic C operations like loops, conditionals, IO operations, as well as more complex operations like counting divisors.

## Homework 3
### prog3.c:
This C program contains multiple functions that perform a range of arithmetic and character shifting operations, each with corresponding tests. The program includes:

- **sum3()**: This function takes four arguments: three integers (a, b, and c) and a pointer to an integer (sum). If the pointer isn't NULL, the function computes the sum of a, b, and c and assigns the result to the memory location pointed to by sum.

- **testSum3()**: This function provides test cases to ensure that sum3() is working correctly. The tests involve calling sum3() with known values and using the assert() function to verify the results.

- **compareArrays()**: This function compares two float arrays of a given length. If the arrays are identical, it returns 1 and assigns -1 to the memory location pointed to by pos. If the arrays are not identical, it returns 0 and assigns the index of the first differing pair to the memory location pointed to by pos. If any of the parameters are NULL, it returns -1.

- **testCompareArrays()**: This function contains test cases for compareArrays(), ensuring its correctness using assert().

- **performShiftCipher()**: This function performs a Caesar cipher, a type of substitution cipher, on a string of text. It shifts each letter in the string by a number of places defined by the integer argument k. The result is stored in the outputText array. If the shift would move a letter outside the range of the alphabet, it wraps around. If the shift amount is outside the range of [-MAX_SHIFT_CIPHER_KEY, MAX_SHIFT_CIPHER_KEY] or if either the input or output string is NULL, the function returns appropriate error values.

- **testPerformShiftCipher()**: This function conducts various test cases to ensure the correctness of the performShiftCipher() function.

This program is a great demonstration of the use of pointers, arrays, characters, and testing in the C programming language. The code is written to handle multiple scenarios and edge cases, making it robust and reliable.

## Homework 4
### arr_utils.c:
This file contains the definition of two functions:

- **sumArrs()**: It takes three integer arrays (arr1, arr2, outputArr) and an integer (len) as input. The function calculates the sum of arr1 and arr2 and stores the result in outputArr. If any of the array pointers is NULL, the function returns 0; otherwise, it returns 1.

- **minAtSameIndex()**: It takes four arrays (arr1, arr2, arr3, index) and an integer len. The function finds the minimum value in each array and checks if these minimums are all at the same index. If they are, the function updates index to this minimum index value. The function returns 1 if successful and 0 otherwise, e.g., if any array is NULL.

### str_utils.c: 
This file contains the definition of two functions:

- **strrpbrk()**: Given a string (str) and a set of characters (targets), the function finds the last occurrence in str of any character in targets and returns a pointer to this location. If str or targets is NULL, the function returns NULL.

- **parseForHighest()**: Given a string (input) and a pointer to an integer (highest), this function parses input for numbers (delimited by ';'), and sets highest to the highest number found. The function returns 1 if input and highest are not NULL and 0 otherwise.

## Homework 5
### prog5.c: 
This file provides utilities for processing matrices and performing transformations on arrays of strings.

- **calculateRowSums()**: This function takes a 2D integer array (vals), the number of rows (numRows), and an array of row widths (rowWidths) as input. It calculates the sum of each row and returns a dynamically-allocated array containing these sums. If any input pointer is NULL or an individual row in vals is NULL, the function returns 0.

- **sumArrays()**: This function takes an integer array (array) and its length (length). It calculates and returns the sum of the elements in the array.

- **sumSubsquare()**: This function takes a 2D integer array (arr), the number of rows (numRows) and columns (numCols), start and end indices for both rows (rowStart, rowEnd) and columns (colStart, colEnd), and a pointer to an integer (result). It calculates and stores the sum of the sub-square specified by the start and end indices in result. If any pointer is NULL, if the start or end indices are out of bounds, or if the start indices are greater than the end indices, the function returns 0. If successful, the function returns 1.

- **applyTransformation()**: This function takes an array of strings (strings), the number of strings (numStrings), and a pointer to a function that takes a string and returns an integer (transform). It applies transform to each string and returns a dynamically-allocated array containing the results.

This utility provides robust tools for matrix operations and transformations on strings. It comes with a multitude of error checks to ensure safe and correct operation. This program might be useful in a variety of applications, including mathematical computations and data transformations.

## Homework 6
### my_strtok.c:
This C program, `my_strtok.c`, offers a custom implementation of the `strtok` function available in C's standard library. This function, `myStrtok`, tokenizes a given string `str` based on a set of delimiters specified by `delims`. It will return the next token each time it's called until no more tokens can be extracted. If the `str` is `NULL`, it continues tokenizing from the last string it processed. If `str` and `delims` are `NULL`, it returns `NULL`. Note that `myStrtok` uses a static variable `string` to keep track of the position in the last string it processed.

### replace.c:
The `replace.c` program is a text processing tool for replacing a specified pattern within a range of lines in a text file. Given two files (input and output), a range of lines (start line and end line), and two strings (pattern and replacement pattern), the program scans the input file line by line. If the current line number is within the given range and the line contains the specified pattern, the program replaces the pattern with the new pattern and writes the line to the output file. Otherwise, it copies the line from the input file to the output file as is. It handles various types of errors like incorrect command-line arguments, inability to open files, or negative line numbers.

### store.c:
The `store.c` program models a store and its operations. The store and its inventory are defined in a struct named `Store` containing the store's name, the number of items in the store, and a pointer to an array of `Item` structs. Each `Item` struct holds an item's name, price, and the number in stock. 

The program provides several functions for managing a `Store`:

- *initStore*: Initializes a `Store` using data from a provided text file (`fileName`).
- *getCheapestItem*: Returns a pointer to the `Item` with the lowest price in a given `Store`.
- *deallocateStore*: Frees all dynamically allocated memory associated with a given `Store`.
- *printStoreItems*: Prints out all the items available in a given `Store`.

It is useful for managing and querying inventory in a store. The store data is read from a text file whose format is specific to this application. The text file should contain, on its first line, the number of items in the store, followed by lines each representing an item with fields (name, price, and number in stock) separated by spaces.
