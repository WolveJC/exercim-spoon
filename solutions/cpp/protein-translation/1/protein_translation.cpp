#include "protein_translation.h"
#include <map>
using namespace std;

namespace protein_translation {

vector<string> proteins(string rna) {
    // Tabla de mapeo: Codon -> Aminoácido
    static const map<string, string> codon_table = {
        {"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, 
        {"UUC", "Phenylalanine"}, {"UUA", "Leucine"},
        {"UUG", "Leucine"}, {"UCU", "Serine"},
        {"UCC", "Serine"}, {"UCA", "Serine"},
        {"UCG", "Serine"}, {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"}, {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},{"UGG", "Tryptophan"}
    };

    vector<string> result;
    for (size_t i = 0; i < rna.length(); i += 3){
        string codon = rna.substr(i,3);
        if (codon == "UAA" || codon == "UAG" || codon == "UGA") break;
        auto it = codon_table.find(codon);
        if (it != codon_table.end()) result.push_back(it->second);
    }
    return result;
}
}