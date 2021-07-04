#include "calPrime.hpp"
#include <vector>
using namespace std;

#if defined(sieve_v1)
int cal_prime_number_under_n(int n) {
    vector<bool> prime_vec(n+1, true);
    prime_vec[0] = false;
    prime_vec[1] = false;
    for(int i=2; i<=n ;i++) {
        if(prime_vec[i]) {
            for(int j=2*i; j<prime_vec.size(); j+=i) {
                prime_vec[j] = false;
            }
        }
    }
    int num = 0;
    for(int i=0; i<prime_vec.size(); i++) {
        if(prime_vec[i]) num++;
    }
    return num;
}
#elif defined(sieve_v2)
vector<bool> prime_vec;

void filterout_composite_number(int base) {
    for(int j=2*base; j<prime_vec.size(); j+=base) {
        prime_vec[j] = false;
    }
}

int cal_prime_number_under_n(int n) {
    prime_vec.resize(n+1, true);
    prime_vec[0] = false;
    prime_vec[1] = false;
    for(int i=2; i<=n ;i++) {
        if(prime_vec[i]) {
            filterout_composite_number(i);
        }
    }
    int num = 0;
    for(int i=0; i<prime_vec.size(); i++) {
        if(prime_vec[i]) num++;
    }
    return num;
}
#elif defined(sieve_v3)
#include <thread>
#define NUM_THREADS 4
vector<bool> prime_vec;

void filterout_composite_number(int base) {
    for(int j=2*base; j<prime_vec.size(); j+=base) {
        prime_vec[j] = false;
    }
}

static int get_prime(int term) {
    static int idx = 0;
    for(idx++; idx<term; idx++) {
        if(prime_vec[idx]) return idx;
    }
    return 0;
}

int cal_prime_number_under_n(int n) {
    prime_vec.resize(n+1, true);
    prime_vec[0] = false;
    prime_vec[1] = false;

    vector<thread> tHandles(NUM_THREADS);

    int base;
    while(1) {
        base=get_prime(n);
        if(base==0) break;
        for(int i=0;; i++) {
            if(!tHandles[i].joinable()) {
                tHandles[i] = thread(filterout_composite_number, base);
                break;
            }
            if(i==3) {
                tHandles[3].join();
                i=-1;
            }
        }
    }

    for(int j=0; j<NUM_THREADS; j++) {
        tHandles[j].join();
    }

    int num = 0;
    for(int i=0; i<prime_vec.size(); i++) {
        if(prime_vec[i]) num++;
    }
    return num;
}
#endif
