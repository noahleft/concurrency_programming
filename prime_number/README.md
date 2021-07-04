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

