CC = gcc
CFLAGS = -Wall -g

INC = -Iinc -Iunity
LINK = -lm

UNITY_SRC = unity/unity.c

PROJECT = Voter
SRC = $(wildcard src/*.c)
MAIN = main.c

ifeq ($(OS),Windows_NT)
		RM = del /q
		EXEC = $(PROJECT).exe
		EXEC_TEST = test/test_$(PROJECT).exe
else
		RM = rm
		EXEC = $(PROJECT).out
		EXEC_TEST = test/test_$(PROJECT).out
endif


$(EXEC): $(SRC) $(MAIN)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LINK)

run: $(EXEC)
	./$(EXEC)

clean:
	$(RM) $(EXEC)

$(EXEC_TEST): $(UNITY_SRC) $(SRC) test/tests.c
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LINK) -D UNITTEST

runtests: $(EXEC_TEST)
	./$(EXEC_TEST)

cleantest:
	cd test && $(RM) *.exe && cd ..

valgrind: $(EXEC) 
	valgrind ./$(EXEC)

coverage: $(SRC) $(MAIN)
	$(CC) -fprofile-arcs -ftest-coverage $(INC) $^ -o $(EXEC) $(LINK)
	./$(EXEC) 
	gcov -a main.c
	$(RM) *.gcda
	$(RM) *.gcno

cleanall: clean cleantest

