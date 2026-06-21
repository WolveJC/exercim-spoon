#pragma once
#include <string>

namespace date_independent {

    class clock {
        private:
        int m_total_minutes;

        // Función auxiliar para normalizar al rango de un día
        static int normalize_minutes(int minutes);

        // Constructor privado que recibe minutos
        explicit clock(int total_minutes);

        public:
        // Función de fábrica para crear un reloj desde horas y minutos
        static clock at(int hours, int minutes);

        // Métodos de añadir y restar
        clock plus(int minutes_to_add) const;
        clock minus(int minutes_to_sub) const;

        // Operador de conversión a string (Formato "HH:MM")
        operator std::string() const;

        // Sobrecarga del operador de igualdad para comparar dos relojes
        bool operator == (const clock& other) const;
        bool operator != (const clock& other) const;
    };

} 