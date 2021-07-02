#include <iostream>
#include <vector>
#include "calPrime.hpp"
using namespace std;

int main() {

    int N = 100000; // # of prime num under 100k is 9592
    // int N = 1000000; // # of prime num under 1M is 78498
    cout<< "# of prime number under " << N << " : " << cal_prime_number_under_n(N) <<endl;

    return 0;
}