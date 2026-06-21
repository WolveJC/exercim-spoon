#include "clock.h"
#include <iomanip>
#include <sstream>

using namespace std;

namespace date_independent {

    // Absorbe sobregiros positivos y negativos
    int clock::normalize_minutes(int minutes) {
        int total_day_minutes = 24 * 60;
        return ((minutes % total_day_minutes) + total_day_minutes) % total_day_minutes;
    }

    // Constructor privado
    clock::clock(int total_minutes): m_total_minutes(total_minutes) {}

    // Método de creación seguro
    clock clock::at(int hours, int minutes) {
        int total = (hours * 60) + minutes;
        return clock(normalize_minutes(total));
    }

    // Sumar minutos es simplemente crear un nuevo reloj con la aritmética acumulada
    clock clock::plus(int minutes_to_add) const {
        return clock(normalize_minutes(m_total_minutes + minutes_to_add));
    }

    // Restar minutos reutiliza la misma lógica
    clock clock::minus(int minutes_to_sub) const {
        return clock(normalize_minutes(m_total_minutes - minutes_to_sub));
    }

    // Formatear texto usando streams de C++
    clock::operator string() const {
        int hours = m_total_minutes / 60;
        int minutes = m_total_minutes % 60;

        ostringstream ss;
        ss << setfill('0') << setw(2) << hours << ":"
        << setfill('0') << setw(2) << minutes;
        return ss.str();
    }

    // Comparación directa de un solo entero
    bool clock::operator == (const clock& other) const {
        return m_total_minutes == other.m_total_minutes;
    }

    bool clock::operator != (const clock& other) const {
        return !(*this == other);
    }

}