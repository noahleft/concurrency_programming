#include <iostream>
#include <vector>
using namespace std;

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

int main() {

    int N = 1000000; // # of prime num under 1M is 78498
    cout<< "# of prime number under " << N << " : " << cal_prime_number_under_n(N) <<endl;

    return 0;
}