SRC      = main.cc \
	   wordcounter.cc
OBJ      = $(SRC:.cc=.o)
BIN      = a.out
CXX      = clang++
CXXFLAGS = -O0 -std=c++11 -ggdb -Weverything -Wno-c++98-compat

all    : $(BIN)

$(BIN) : $(OBJ)
	 $(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN)

clean  :
	rm -f $(OBJ) $(BIN) *~
