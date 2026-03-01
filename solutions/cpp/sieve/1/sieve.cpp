#include "sieve.h"
using namespace std;

namespace sieve {
    vector<int>primes(int limit){
        if (limit < 2) return {};
        // 1. Fase de Preparación: Todos son candidatos (true)
        vector<bool>is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;
        
        // 2. Fase de Filtrado
        for (int p = 2; p * p <= limit; p++){
            if (is_prime[p]){
                for (int i = p * p; i <= limit; i+=p){
                    is_prime[i] = false;
                }
            }
        }
        
        // 3. Fase de Recolección
        vector<int> result;
        for(int p = 2; p <= limit; p++){
            if (is_prime[p]){
                result.push_back(p);
            }
        }return result;
    }

}  // namespace sieve
