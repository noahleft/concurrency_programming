

cxx_source = main.cpp prime.cpp sieve.cpp

all: prog prog_task prog_task_pthread \
	 prog_sieve prog_sieve_task prog_sieve_task_thread

prog: $(cxx_source)
	g++ -Dv1 $^ -o $@
	time ./$@

prog_task: $(cxx_source)
	g++ -Dv2 $^ -o $@
	time ./$@

prog_task_pthread: $(cxx_source)
	g++ -Dv3 $^ -lpthread -o $@
	time ./$@

prog_sieve: $(cxx_source)
	g++ -Dsieve_v1 $^ -o $@
	time ./$@

prog_sieve_task: $(cxx_source)
	g++ -Dsieve_v2 $^ -o $@
	time ./$@

prog_sieve_task_thread: $(cxx_source)
	g++ -std=c++11 -Dsieve_v3 $^ -o $@
	time ./$@

clean:
	rm prog*