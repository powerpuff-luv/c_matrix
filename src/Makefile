CC = gcc
CFLAGS = -Wall -Werror -Wextra
GET_OBJECTS = -Wall -Werror -Wextra -std=c11 -c
ALL_SOURCE = function_files/*.c
ALL_TESTS = tests/*.c
ALL_OBJECTS = *.o
LIBS = -lcheck $(shell pkg-config --cflags --libs check) 

GOAL = s21_matrix.a

all: $(GOAL)

$(GOAL):
	$(CC) $(GET_OBJECTS) $(ALL_SOURCE)
	ar r $(GOAL) $(ALL_OBJECTS)

test: $(GOAL)
	$(CC) $(CFLAGS) $(ALL_TESTS) $(GOAL) -o test $(LIBS)
	./test

build_test: $(GOAL)
	$(CC) $(CFLAGS) $(ALL_TESTS) $(GOAL) -o test $(LIBS)

timeit_test: $(GOAL)
	$(CC) $(CFLAGS) $(ALL_TESTS) $(GOAL) -o test $(LIBS)
	timeit ./test

gcov_report: $(GOAL)
	gcc --coverage  $(ALL_SOURCE) $(ALL_TESTS) -o test $(LIBS)
	./test
	gcovr --exclude-throw-branches -d --html tests.html
	open tests.html

gcov_details: $(GOAL)
	gcc -lcheck --coverage $(ALL_SOURCE) $(ALL_TESTS) -o test $(LIBS)
	./test
	gcovr --exclude-throw-branches -d --html-details tests.html
	open tests.html

debug: $(GOAL)
	gcc $(ALL_SOURCE) $(ALL_TESTS) -g -o debug $(LIBS)
	gdb ./debug

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i function_files/* tests/* *.h
	rm -rf .clang-format

style-check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n function_files/* tests/* *.h
	rm -rf .clang-format

valgrind: clean build_test
	valgrind --leak-check=full --show-leak-kinds=all ./test
#	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
#	valgrind --tool=memcheck --leak-check=yes ./test

cppcheck:
	cppcheck $(ALL_SOURCE) $(ALL_TESTS) --check-level=exhaustive

clean:
	rm -rf *.o *.gcda *.gcno *.a *.gcna *.gch .clang-format *.css *.html test debug

rebuild: clean test