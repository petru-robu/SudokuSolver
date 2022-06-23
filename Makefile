# MakeFile - Linux
# Needs working g++, if not on path rename CC variable
 PROGRAM_NAME =Sudoku

 CSTD = c++17

 flags_all = -std=$(CSTD) -g -O0 -Wall -Wextra -fsanitize=address,undefined,signed-integer-overflow
 flags_fast = -std=$(CSTD) -O2

 INC_PARAMS = -Iinclude/
 SCR_PARAMS = src/*.cpp *.cpp

 LIB_PARAMS = -lsfml-graphics -lsfml-window -lsfml-system

 # make all creates sanitized binary, overflows, illegal memory accesses and undefined behaviour raise an exception
 all: $(sources)
	g++ $(flags_all) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out

 # make fast compiles with -O2 flag
 fast: $(sources)
	g++ $(flags_fast) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out

 # removes a.out file
 clean:
	rm $(PROGRAM_NAME).out

 run: $(sources)
	g++ $(flags_all) $(INC_PARAMS) $(SCR_PARAMS) $(LIB_PARAMS) -o $(PROGRAM_NAME).out
	./$(PROGRAM_NAME).out
