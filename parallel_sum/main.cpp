#include <iostream>
#include <vector>
#include "calParallelSum.hpp"
using namespace std;

int main() {
    vector<int> data(1000, 1);

    cout<<"sumup:"<<calParallelSum(data)<<endl;
    return 0;
}
