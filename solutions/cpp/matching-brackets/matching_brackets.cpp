#include "matching_brackets.h"
using namespace std;

namespace matching_brackets {
    bool check(string text){
        stack<char> pil;
        for (char c : text){
            switch(c){
                // Fase de Apertura: Promesas de cierre
                case '{':
                case '[':
                case '(':
                pil.push(c);
                break;
                // Fase de Cierre: Verificación de coherencia
                case '}':
                    if(pil.empty() || pil.top() != '{') return false;
                    pil.pop();
                    break;
                case ']':
                    if(pil.empty() || pil.top() != '[') return false;
                    pil.pop();
                    break;
                case ')':
                    if(pil.empty() || pil.top() != '(') return false;
                    pil.pop();
                    break;
                //Cualquier otra cosa, ignoralo
                default:
                    break;
            }
        }return pil.empty(); //Si la pila está vacía (sin promesas de cierre), todo está en orden
    }
}
