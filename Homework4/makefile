CC=gcc
CFLAGS= -Wall -Werror -g
DEPS = arr_utils.h,str_utils.h

test_str_utils: test_str_utils.c str_utils.o 
	$(CC) test_str_utils.c str_utils.o -o test_str_utils

test_arr_utils: test_arr_utils.c arr_utils.o
	$(CC) test_arr_utils.c arr_utils.o -o test_arr_utils

clean: 
	rm test_str_utils str_utils.o test_arr_utils arr_utils.o
