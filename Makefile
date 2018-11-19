SRC = main.cc

all : $(SRC)
	clang++ -Weverything -Wno-c++98-compat $(SRC)
