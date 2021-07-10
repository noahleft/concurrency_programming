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

typedef struct thread_param {
    vector<bool> prime_vec;
    int base;
} tparam_t;

void filterout_composite_number(tparam_t *pArgs) {
    vector<bool> &prime_vec = pArgs->prime_vec;
    int base = pArgs->base;
    for(; base<prime_vec.size(); base+=NUM_THREADS) {
        if(!prime_vec[base]) continue;
        for(int j=2*base; j<prime_vec.size(); j+=base) {
            prime_vec[j] = false;
        }
    }
}

int cal_prime_number_under_n(int n) {

    vector<thread> tHandles(NUM_THREADS);
    vector<tparam_t> tParams(NUM_THREADS);

    for(int i=0; i<NUM_THREADS; i++) {
        // thread parameter initialization
        // Be aware that data complexity is O(n) for each thread.
        tParams[i].prime_vec.resize(n+1, true);
        tParams[i].prime_vec[0] = false;
        tParams[i].prime_vec[1] = false;
        tParams[i].base = i;
        tHandles[i] = thread(filterout_composite_number, &tParams[i]);
    }

    for(int j=0; j<NUM_THREADS; j++) {
        tHandles[j].join();
    }

    // reduce: combine the thread data
    vector<bool> prime_vec;
    prime_vec.resize(n+1, true);
    for(int i=0; i<prime_vec.size(); i++) {
        for(int j=0; j<NUM_THREADS; j++) {
            if(!tParams[j].prime_vec[i]) {
                prime_vec[i] = false;
                break;
            }
        }
    }

    int num = 0;
    for(int i=0; i<prime_vec.size(); i++) {
        if(prime_vec[i]) num++;
    }
    return num;
}
#endif
