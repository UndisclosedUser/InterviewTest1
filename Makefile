SRC = 	main.cc \
	wordcounter.cc

all : $(SRC)
	clang++ -ggdb -Weverything -Wno-c++98-compat $(SRC)

clean :
	rm -f *~ a.out
