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
    vector<int> prime_vec;
    for(int i=2; i<=n ;i++) {
        if(is_prime(i)) {
            prime_vec.push_back(i);
        }
    }
    return prime_vec.size();
}
#elif defined(v3)
#include <pthread.h>
#define NUM_THREADS 4
pthread_mutex_t gLock;
int num;

vector<int> prime_vec;
static bool is_prime(int t) {
    for(int i=2; i<=t/2; i++) {
        if(t%i==0) return false;
    }
    return true;
}

void *threadFunc(void *pArg) {
    int i = *((int *)pArg);
    for(; i<=num ;i+=NUM_THREADS) {
        if(is_prime(i)) {
            pthread_mutex_lock(&gLock);
            prime_vec.push_back(i);
            pthread_mutex_unlock(&gLock);
        }
    }
    return NULL;
}

int cal_prime_number_under_n(int n) {
    num = n;
    pthread_t tHandles[NUM_THREADS];
    int tNum[NUM_THREADS];
    pthread_mutex_init(&gLock, NULL);

    for(int i=0; i<NUM_THREADS; i++) {
        tNum[i] = 2+i;
        pthread_create(&tHandles[i], NULL, threadFunc, (void*) &tNum[i]);
    }

    for(int j=0; j<NUM_THREADS; j++) {
        pthread_join(tHandles[j], NULL);
    }

    pthread_mutex_destroy(&gLock);
    return prime_vec.size();
}
#endif


