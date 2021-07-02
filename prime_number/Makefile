

cxx_source = main.cpp prime.cpp

all: prog prog_algo prog_pthread

prog: $(cxx_source)
	g++ -Dv1 $^ -o $@
	time ./$@

prog_algo: $(cxx_source)
	g++ -Dv2 $^ -o $@
	time ./$@

prog_pthread: $(cxx_source)
	g++ -Dv3 $^ -lpthread -o $@
	time ./$@

clean:
	rm prog*