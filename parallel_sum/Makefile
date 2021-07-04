

cxx_source = main.cpp sum.cpp

all: prog

prog: $(cxx_source)
	g++ $^ -o $@
	time ./$@

clean:
	rm prog*