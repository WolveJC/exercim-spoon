#pragma once
#include <string>
#include <vector>

namespace robot_name {

class robot {
private:
    std::string m_name;

    // Herramientas globales de la fábrica (Compartidas por todas las instancias)
    static std::vector<int> s_name_pool;
    static size_t s_pool_index;
    static bool s_factory_initialized;

    // Métodos privados internos
    static void initialize_factory();
    void generate_new_name();

public:
    // Constructor: El robot nace encendido y con nombre
    robot();

    // Método de acceso al nombre
    std::string name() const;

    // Reinicio de fábrica
    void reset();
};

} 
