#include "robot_name.h"
#include <random>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace robot_name {

    //Inicializar varibles globales
    vector < int > robot::s_name_pool;
    size_t robot::s_pool_index = 0;
    bool robot::s_factory_initialized = false;

    void robot::initialize_factory() {
        if (s_factory_initialized) return;

        // 1. Generar secuencialmente los 676,000 identificadores
        s_name_pool.resize(676000);
        for (int i = 0; i < 676000; ++i) {
            s_name_pool[i] = i;
        }

        // 2. Mezclar el vector con un motor aleatorio (Mersenne Twister)
        random_device rd;
        mt19937 g(rd());
        shuffle(s_name_pool.begin(), s_name_pool.end(), g);

        s_factory_initialized = true;
    }

    void robot::generate_new_name() {
        // Inicializar la fábrica si es el primer robot de la historia
        if (!s_factory_initialized) {
            initialize_factory();
        }

        // Si nos quedamos sin nombres en el mundo
        if (s_pool_index >= s_name_pool.size()) {
            throw std::runtime_error("Fábrica llena: Se agotaron los nombres únicos.");
        }

        // Tomamos el ID aleatorio actual
        int name_id = s_name_pool[s_pool_index++];

        // Desarmamos matemáticamente el ID en el formato AA123
        int digits = name_id % 1000;
        name_id /= 1000;

        char letter2 = 'A' + (name_id % 26);
        char letter1 = 'A' + (name_id / 26);

        // Construimos la cadena eficientemente
        m_name = "";
        m_name += letter1;
        m_name += letter2;

        // Formatear los 3 dígitos asegurando ceros a la izquierda si es necesario
        if (digits < 10) m_name += "00" + to_string(digits);
        else if (digits < 100) m_name += "0" + to_string(digits);
        else m_name += to_string(digits);
    }

    // Constructor
    robot::robot() {
        generate_new_name();
    }

    string robot::name() const {
        return m_name;
    }

    void robot::reset() {
        // Al resetear, simplemente descartamos el nombre viejo y consumimos el siguiente de la lista
        generate_new_name();
    }

}