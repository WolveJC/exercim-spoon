#include "prime_factors.h"
using namespace std;

namespace prime_factors {
    vector<long long> of (long long n){
        vector<long long> factors;
        // 1. Extraer todos los 2 (único primo par)
        while (n % 2 == 0){
            factors.push_back(2);
            n /= 2;
        }
        // 2. Probar solo números impares desde 3
        for (long long d = 3; d * d <= n; d+=2){
            while (n % d == 0) {
                factors.push_back(d);
                n /= d;
            }
        }
        // 3. Si queda algo, es un factor primo mayor que la raíz cuadrada
        if (n > 1) factors.push_back(n);
        return factors;
    }
}
