# calculate how many prime number under N?

Complete the function int cal_prime_number_under_n(int n)

**Version1: brute force**
- if m is prime number, then none of prime number less than m is a product of m.
 
        g++ -Dv1 main.cpp prime.cpp -o prog
        time ./prog
        # of prime number under 1000000 : 78498
            22.82 real        19.70 user         0.30 sys

**Version2: rewrite to task independent algo**
- if m is prime number, then none of number less than m is a product of m.

        g++ -Dv2 main.cpp prime.cpp -o prog_algo
        time ./prog_algo
        # of prime number under 1000000 : 78498
            128.62 real       121.48 user         1.31 sys
**Version3: lock-free algo on task independent algo**
- if m is prime number, then none of number less than m is a product of m.
- threading m = [4k, 4k+1, 4k+2, 4k+3]

        g++ -Dv3 main.cpp prime.cpp -lpthread -o prog_pthread
        time ./prog_pthread
        # of prime number under 1000000 : 78498
            72.73 real       137.42 user         0.72 sys

**Version4: sieve algorithm**
- if m is prime number, then composite of m are NOT prime number.
 
        g++ -Dsieve_v1 main.cpp prime.cpp sieve.cpp -o prog_sieve
        time ./prog_sieve
        # of prime number under 100000000 : 5761455
            10.18 real         9.80 user         0.05 sys

**Version5: refactor the task function**
- if m is prime number, then composite of m are NOT prime number.

        g++ -Dsieve_v2 main.cpp prime.cpp sieve.cpp -o prog_sieve_task
        time ./prog_sieve_task
        # of prime number under 100000000 : 5761455
            10.43 real         9.73 user         0.06 sys
**Version6: lock-free algo on task function**
- if m is prime number, then composite of m are NOT prime number.
- threading m = [4k, 4k+1, 4k+2, 4k+3]

        g++ -std=c++11 -Dsieve_v3 main.cpp prime.cpp sieve.cpp -o prog_sieve_task_thread
        time ./prog_sieve_task_thread
        # of prime number under 100000000 : 5761455
            5.78 real        12.09 user         0.02 sys


