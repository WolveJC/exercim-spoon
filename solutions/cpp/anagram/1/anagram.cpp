#include "anagram.h"
#include <algorithm>
#include <cctype>

using namespace std;

namespace anagram {

// Convierte un string a minúsculas usando transformaciones
string anagram::to_lowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return str;
}

// Constructor: Aplica optimización con pre-calculo
anagram::anagram(const string& target) : m_target_original(target) {
    m_target_lowercase = to_lowercase(m_target_original);
    m_target_sorted = m_target_lowercase;
    sort(m_target_sorted.begin(), m_target_sorted.end());
}

vector<string> anagram::matches(const vector<string>& candidates) const {
    vector<string> result;

    for (const string& candidate : candidates) {
        // Regla 1: Si miden distinto, no pueden ser anagramas
        if (candidate.length() != m_target_lowercase.length()) {
            continue;
        }

        string candidate_lowercase = to_lowercase(candidate);

        // Regla 2: Una misma palabra NO es su propio anagrama
        if (candidate_lowercase == m_target_lowercase) {
            continue;
        }

        // Regla 3: Ordenar la candidata en minúsculas
        string candidate_sorted = candidate_lowercase;
        sort(candidate_sorted.begin(), candidate_sorted.end());

        // Si coinciden, es un anagrama legítimo
        if (candidate_sorted == m_target_sorted) {
            result.push_back(candidate);
        }
    }

    return result;
}

}
