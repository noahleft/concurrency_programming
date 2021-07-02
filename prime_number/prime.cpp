#include "calPrime.hpp"
#include <vector>
using namespace std;

#if defined(v1)
int cal_prime_number_under_n(int n) {
    vector<int> prime_vec;
    for(int i=2; i<=n ;i++) {
        int j;
        for(j=0; j<prime_vec.size(); j++) {
            if( i%prime_vec[j]==0) {
                break;
            }
        }
        if(j==prime_vec.size()) {
            prime_vec.push_back(i);
        }
    }
    return prime_vec.size();
}
#elif defined(v2)
static bool is_prime(int t) {
    for(int i=2; i<=t/2; i++) {
        if(t%i==0) return false;
    }
    return true;
}

int cal_prime_number_under_n(int n) {
    int num = 0;
    for(int i=2; i<=n ;i++) {
        if(is_prime(i)) {
            num++;
        }
    }
    return num;
}
#elif defined(v3)
#include <pthread.h>
#define NUM_THREADS 4

typedef struct thread_param
{
    int seed;
    int terminate_number;
    int result;
} tparam_t;

static bool is_prime(int t) {
    for(int i=2; i<=t/2; i++) {
        if(t%i==0) return false;
    }
    return true;
}

void *threadFunc(void *pArg) {
    int seed = ((tparam_t *)pArg)->seed;
    int term = ((tparam_t *)pArg)->terminate_number;
    int num = 0;
    for(int i = seed; i<=term ;i+=NUM_THREADS) {
        if(is_prime(i)) {
            num++;
        }
    }
    ((tparam_t *)pArg)->result = num;
    return NULL;
}

int cal_prime_number_under_n(int n) {
    pthread_t tHandles[NUM_THREADS];
    tparam_t tParam[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++) {
        tParam[i].seed = 2+i;
        tParam[i].terminate_number = n;
        pthread_create(&tHandles[i], NULL, threadFunc, (void*) &tParam[i]);
    }

    int num = 0;
    for(int j=0; j<NUM_THREADS; j++) {
        pthread_join(tHandles[j], NULL);
        num+=tParam[j].result;
    }
    return num;
}
#endif


