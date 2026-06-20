#include "space_age.h"

namespace space_age {

// 1. Constructor con lista de inicialización
space_age::space_age(double seconds) : m_seconds(seconds) {}

// 2. Método para recuperar los segundos
double space_age::seconds() const {
    return m_seconds;
}

// 3. Cálculo base para la Tierra
double space_age::on_earth() const {
    return m_seconds / EARTH_YEAR_IN_SECONDS;
}

// 4. Conversiones planetarias directas
double space_age::on_mercury() const {
    return on_earth() / MERCURY_ORBITAL_FACTOR;
}

double space_age::on_venus() const {
    return on_earth() / VENUS_ORBITAL_FACTOR;
}

double space_age::on_mars() const {
    return on_earth() / MARS_ORBITAL_FACTOR;
}

double space_age::on_jupiter() const {
    return on_earth() / JUPITER_ORBITAL_FACTOR;
}

double space_age::on_saturn() const {
    return on_earth() / SATURN_ORBITAL_FACTOR;
}

double space_age::on_uranus() const {
    return on_earth() / URANO_ORBITAL_FACTOR;
}

double space_age::on_neptune() const {
    return on_earth() / NEPTUNE_ORBITAL_FACTOR;
}

}