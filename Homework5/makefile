CC := gcc
CFLAGS := -Wall -Werror -g

all: prog5.o test_prog5

prog5.o: prog5.c prog5.h
	$(CC) $(CFLAGS) -c $< -o $@

test_prog5: test_prog5.c prog5.o
	$(CC) $(CFLAGS) $^ -o $@

demoCRS: demo_calculateRowSums.c prog5.o
	$(CC) $(CFLAGS) $^ -o $@

demoSSS: demo_sumSubsquare.c prog5.o
	$(CC) $(CFLAGS) $^ -o $@

demoAT: demo_applyTransformation.c prog5.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf prog5.o test_prog5 test_prog5.dSYM
