#include <iostream>
#include <vector>
#include "calPrime.hpp"
using namespace std;

int main() {

#if defined(v1) || defined(v2) || defined(v3)
    int N = 100000; // # of prime num under 100k is 9592
#elif defined(sieve_v1) || defined(sieve_v2) || defined(sieve_v3)
    int N = 10000000; // # of prime num under 10M is 664579
#else
    int N = 1000000; // # of prime num under 1M is 78498
#endif
    cout<< "# of prime number under " << N << " : " << cal_prime_number_under_n(N) <<endl;

    return 0;
}