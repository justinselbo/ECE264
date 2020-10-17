WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_MAIN -DTEST_READDATA -DTEST_WRITEDATA -DTEST_MERGE -DTEST_MERGESSORT #-DDEBUG

SRCS = main.c hw09.c
OBJS = $(SRCS:%.c=%.o)

hw09: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw09

.c.o: 
	$(GCC) $(TESTFLAGS) $(VAL) -c $*.c 

testall: test1 test2 test3 test4 test5

test1: hw09
	./hw09 inputs/input1  output1
	diff -w output1 expected/expected1

test2: hw09
	./hw09 inputs/input2  output2
	diff -w output2 expected/expected2

test3: hw09
	./hw09 inputs/input3  output3
	diff -w output3 expected/expected3

test4: hw09
	./hw09 inputs/input4  output4
	diff -w output4 expected/expected4

test5: hw09
	./hw09 inputs/input5  output5
	diff -w output5 expected/expected5

clean: # remove all machine generated files
	rm -f hw09 *.o output*
