#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sumArrays(int *array, int length);

int* calculateRowSums(int** vals, int numRows, int* rowWidths);

int sumSubsquare(int** arr, int numRows, int numCols, int rowStart,
                 int rowEnd, int colStart, int colEnd, int* result);

int* applyTransformation(char **strings, int numStrings,
        int (*transform)(char*));

