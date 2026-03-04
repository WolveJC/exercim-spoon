#include "prime_factors.h"
using namespace std;

namespace prime_factors {
    vector<long long> of (long long n){
        vector<long long> factors;
        long long d = 2;
        while (n > 1){
            while (n % d == 0){
                factors.push_back(d);
                n /= d;
            }d++;
        }return factors;
    }
}
